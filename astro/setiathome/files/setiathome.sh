#!/bin/sh
#
# $FreeBSD$
#
# Start or stop SETI@home, or set up working directory and register.
#

case $0 in
/*) rc_dir=${0%/*} ;;
 *) rc_dir=${PWD:-$(pwd)} ;;
esac
rc_file=${0##*/}
rc_path=${rc_dir}/${rc_file}
rc_arg=$1

# override these variables in ${PREFIX}/etc/rc.setiathome.conf
seti_wrkdir=/var/db/${rc_file%.sh}	# primary working directory
seti_std_args=-email			# command arguments for standard mode
seti_reg_args=-login			# command arguments for register mode
seti_proxy_args=			# proxy arguments
seti_user=setiathome			# user id to run as
seti_group=${seti_user}			# group id to run as
seti_nice=15				# nice level to run at
seti_maxprocs=$(sysctl -n hw.ncpu)	# max. number of processes to start
seti_sleep=21600			# time to sleep between restarts

if ! PREFIX=$(expr ${rc_path} : "\(/.*\)/etc/rc\.d/${rc_file}\$"); then
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
			cd ${seti_wrkdir}/${i} || exit; \
			echo \$\$ > shpid.sah; \
			trap 'kill \$pid;exit' 15; \
			while :; do \
				${program_path} \
					${seti_std_args} ${seti_proxy_args} \
					${seti_nice:+-nice} ${seti_nice} & \
				pid=\$!; wait \$pid; \
				sleep ${seti_sleep}; \
			done > /dev/null" &
	done
	echo -n " SETI@home"
	;;

stop)
	for i in ${seti_wrksuff}; do
		for pid_path in ${seti_wrkdir}/${i}/pid.sah \
				${seti_wrkdir}/${i}/shpid.sah; do
			if [ -f ${pid_path} ]; then
				kill $(cat ${pid_path}) 2> /dev/null
			fi
		done
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
	if pw group show "${seti_group}" 2>/dev/null; then
		echo "You already have a group \"${seti_group}\"," \
		     "so I will use it."
	elif pw groupadd ${seti_group} -h -; then
		echo "Added group \"${seti_group}\"."
	else
		echo "Adding group \"${seti_group}\" failed..."
		echo "Please create it, and try again."
		exit 1
	fi
	if pw user show "${seti_user}" 2>/dev/null; then
		echo "You already have a user \"${seti_user}\"," \
		     "so I will use it."
		if pw usermod ${seti_user} -d ${seti_wrkdir}; then
			echo "Changed home directory of \"${seti_user}\"" \
			     "to \"${seti_wrkdir}\""
		else
			echo "Changing home directory of \"${seti_user}\"" \
			     "to \"${setu_wrkdir}\" failed..."
			exit 1
		fi
	elif pw useradd ${seti_user} -g ${seti_group} -h - \
		-d ${seti_wrkdir} -s /sbin/nologin -c "SETI at home Daemon"; then
		echo "Added user \"${seti_user}\"."
	else
		echo "Adding user \"${seti_user}\" failed..."
		echo "Please create it, and try again."
		exit 1
	fi
	# Create or update primary working directory (in case the uid changed)
	mkdir -p ${seti_wrkdir} || exit
	chown -Rh ${seti_user}:${seti_group} ${seti_wrkdir} || exit
	chmod u=Xrw,g=Xr,o=Xr ${seti_wrkdir} || exit
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
