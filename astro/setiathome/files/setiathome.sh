#!/bin/sh

#
# Start or stop setiathome, or set up working directory and register
#

# override these variables in ${PREFIX}/etc/setiathome.conf
seti_wrkdir=/var/db/setiathome		# primary working directory
seti_bindir=!!SUBDIR!!			# exec directory relative to ${PREFIX}
seti_command=setiathome			# command name
seti_std_args=-email			# command arguments for standard mode
seti_reg_args=-login			# command arguments for register mode
seti_user=nobody			# user id to run as
seti_nice=1				# nice level to run at
seti_maxprocs=`sysctl -n hw.ncpu`	# max. number of processes to start
seti_syslog=daemon.err			# syslog facility.level

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/${0##*/}\$"); then
	echo "${0##*/}: Cannot determine PREFIX." >&2
	echo "Please use the complete pathname." >&2
	exit 64
fi

if [ -f ${PREFIX}/etc/setiathome.conf ]; then
	. ${PREFIX}/etc/setiathome.conf
fi

i=${seti_maxprocs}
seti_wrksuff="."
while [ ${i} -gt 1 ]; do
	seti_wrksuff="${seti_wrksuff} ${i}"
	i=`expr ${i} - 1`
done

case $1 in
	start)
		for i in ${seti_wrksuff}; do
			if [ ! -d ${seti_wrkdir}/${i} ]; then
				logger -sp ${seti_syslog} -t ${seti_command} \
					"unable to start: ${seti_wrkdir}/${i} is missing."
				exit 72
			fi
			if [ ! -f ${seti_wrkdir}/${i}/user_info.sah ]; then
				logger -sp ${seti_syslog} -t ${seti_command} \
					"unable to start: please log in to SETI@home first. (${seti_wrkdir}/${i}/user_info.sah is missing.)"
				exit 72
			fi
		done
		for i in ${seti_wrksuff}; do
			su -fm ${seti_user} -c "\
				(cd ${seti_wrkdir}/${i} && \
				 exec ${PREFIX}/${seti_bindir}/${seti_command} \
				 ${seti_std_args} \
				 ${seti_nice+-nice} ${seti_nice} >/dev/null &)"
			echo -n " SETI@home"
		done
		;;

	stop)
		killall ${seti_command}
		;;

	register)
		# Create or update primary working directory (in case the uid changed)
		mkdir -p ${seti_wrkdir}
		chown ${seti_user} ${seti_wrkdir}
		chmod u=Xrw,g=Xr,o=Xr ${seti_wrkdir}
		if [ -f ${seti_wrkdir}/user_info.sah ]; then
			echo "      It seems you have already registered with SETI@home.  Would you like"
			echo -n "      to repeat the procedure? [Y/n] "
			read a
			if [ "X${a}" = "Xn" -o "X${a}" = "XN" ]; then
				seti_dontlogin=yes
			fi
		fi
		# No need to register if we've already done so
		if [ "X${seti_dontlogin}" != "Xyes" ]; then
			su -fm ${seti_user} -c "\
				cd ${seti_wrkdir} && \
				exec ${PREFIX}/${seti_bindir}/${seti_command} \
				${seti_reg_args}"
		fi

		if [ ${seti_maxprocs} -gt 1 ]; then
			echo "      Updating additional working directories."
			i=${seti_maxprocs}
			while [ ${i} -gt 1 ]; do
				mkdir -p ${seti_wrkdir}/${i}
				chown ${seti_user} ${seti_wrkdir}/${i}
				chmod 755 ${seti_wrkdir}/${i}
				# Assume the user want's all processes to run with the same registration
				rm -f ${seti_wrkdir}/${i}/user_info.sah
				ln -sf ../user_info.sah ${seti_wrkdir}/${i}
				i=`expr ${i} - 1`
			done
		fi
		;;		

	*)
		echo "usage: ${0##*/} {start|stop|register}" >&2
		exit 64
		;;
esac
