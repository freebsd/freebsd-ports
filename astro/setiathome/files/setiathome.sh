#!/bin/sh
#
# $FreeBSD$
#
# Start or stop SETI@home, or set up working directory and register.
#

rc_file=${0##*/}
rc_arg=$1

# override these variables in ${PREFIX}/etc/rc.setiathome.conf
seti_wrkdir=/var/db/${rc_file%.sh}	# primary working directory
seti_std_args=-email			# command arguments for standard mode
seti_reg_args=-login			# command arguments for register mode
seti_proxy_args=			# proxy arguments
seti_user=nobody			# user id to run as
seti_nice=15				# nice level to run at
seti_maxprocs=$(sysctl -n hw.ncpu)	# max. number of processes to start

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/${rc_file}\$"); then
	echo "${rc_file}: Cannot determine PREFIX." >&2
	echo "Please use the complete pathname." >&2
	exit 64
fi

rcconf_dir=${PREFIX}/etc
rcconf_file=rc.${rc_file%.sh}.conf
rcconf_path=${rcconf_dir}/${rcconf_file}

if [ -f ${rcconf_path} ]; then
	. ${rcconf_path}
fi

program_dir=${PREFIX}/sbin
program_file=${rc_file%.sh}
program_path=${program_dir}/${program_file}

syslog_facility=daemon.err

i=${seti_maxprocs}
seti_wrksuff="."
while [ ${i} -gt 1 ]; do
	seti_wrksuff="${seti_wrksuff} ${i}"
	i=$((${i} - 1))
done

case "$rc_arg" in
start)
	if [ ! -x ${program_path} ]; then
		logger -sp ${syslog_facility} -t ${program_file} \
			"unable to start: ${program_path} is missing."
		exit 72
	fi
	for i in ${seti_wrksuff}; do
		if [ ! -d ${seti_wrkdir}/${i} ]; then
			logger -sp ${syslog_facility} -t ${program_file} \
			"unable to start: ${seti_wrkdir}/${i} is missing."
			exit 72
		fi
		if [ ! -f ${seti_wrkdir}/${i}/user_info.sah ]; then
			logger -sp ${syslog_facility} -t ${program_file} \
			"unable to start: please log in to SETI@home first" \
			"(${seti_wrkdir}/${i}/user_info.sah is missing)."
			logger -sp ${syslog_facility} -t ${program_file} \
				"run \"$0 register\" to accomplish this."
			exit 72
		fi
	done
	for i in ${seti_wrksuff}; do
		su -fm ${seti_user} -c "\
			(cd ${seti_wrkdir}/${i} && exec ${program_path} \
				 ${seti_std_args} ${seti_proxy_args} \
				 ${seti_nice:+-nice} ${seti_nice} >/dev/null &)"
	done
	echo -n " SETI@home"
	;;

stop)
	for i in ${seti_wrksuff}; do
		pid_path=${seti_wrkdir}/${i}/pid.sah
		if [ -f ${pid_path} ]; then
			kill $(cat ${pid_path}) 2> /dev/null
		fi
	done
	if [ ! -f ${seti_wrkdir}/pid.sah ]; then
		killall ${program_file} 2> /dev/null
	fi
	;;

restart)
	$0 stop
	$0 start
	;;

status)
	ps auxww | egrep ${program_file} | egrep -v "($0|egrep)"
	;;

register)
	if [ ! -x ${program_path} ]; then
		echo "${program_file}:" \
			"unable to register: ${program_path} is missing." >&2
		exit 72
	fi
	# Create or update primary working directory (in case the uid changed)
	mkdir -p ${seti_wrkdir}
	chown ${seti_user} ${seti_wrkdir}
	chmod u=Xrw,g=Xr,o=Xr ${seti_wrkdir}
	seti_dontlogin=no
	if [ -f ${seti_wrkdir}/user_info.sah ]; then
		echo    "      It seems you have already registered with" \
			"SETI@home.  Would you"
		echo -n "      like to repeat the procedure? [Y/n] "
		read a
		if [ "X${a}" = "Xn" -o "X${a}" = "XN" ]; then
			seti_dontlogin=yes
		fi
	fi
	# No need to register if we've already done so
	if [ "X${seti_dontlogin}" != "Xyes" ]; then
		su -fm ${seti_user} -c "\
			cd ${seti_wrkdir} && \
			exec ${program_path} \
			${seti_reg_args} ${seti_proxy_args}"
	fi
	if [ ${seti_maxprocs} -gt 1 ]; then
		echo "      Updating additional working directories."
		i=${seti_maxprocs}
		while [ ${i} -gt 1 ]; do
			mkdir -p ${seti_wrkdir}/${i}
			chown ${seti_user} ${seti_wrkdir}/${i}
			chmod 755 ${seti_wrkdir}/${i}
			# Assume the user want's all processes to run
			# with the same registration
			rm -f ${seti_wrkdir}/${i}/user_info.sah
			ln -sf ../user_info.sah ${seti_wrkdir}/${i}
			i=$((${i} - 1))
		done
	fi
	;;		

*)
	echo "usage: ${rc_file} {start|stop|restart|status|register}" >&2
	exit 64
	;;
esac
