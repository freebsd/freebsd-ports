#!/bin/sh
# taken from misc/dnetc by dbaker@distributed.net

prefix="%%DESTINATION_DIR%%"
ncpu=%%NCPU%%

case "$1" in
start)
	while [ ${ncpu} -gt 0 ];
	do
		# update cpu count
		ncpu=$((${ncpu} - 1))

		# dir for current cpu
		dir="${prefix}/cpu${ncpu}"

		if [ ! -d $dir ]; then
		 logger -i "distribfold client directory doesn't exist. ($dir)."
		 exit
		fi

		if [ ! -f $dir/foldtrajlite ]; then
		 logger -i "distribfold client doesn't exist. ($dir/dfoldtrajlite)."
		 exit
		fi

		if [ ! -f $dir/handle.txt ]; then
		 logger -i "distribfold client is not configured. 'su -m %%DNETFOLD_USER%% -c $dir/foldit' to configure it."
		 echo "distribfold client is not configured. 'su -m %%DNETFOLD_USER%% -c $dir/foldit' to configure it."
		 exit
		fi

		# start client for current cpu
		su -m %%DNETFOLD_USER%% -c "cd $dir && ./foldit" 2>/dev/null >/dev/null &
	done

	echo -n " distribfold"
	;;
stop)
	while [ ${ncpu} -gt 0 ];
	do
		# update cpu count
		ncpu=$((${ncpu} - 1))

		# dir for current cpu
		dir="${prefix}/cpu${ncpu}"

		rm -f $dir/foldtrajlite.lock
	done

	# give clients enough time to shutdown
	# 5 seconds minimum + 5 seconds per number of clients
	sleep $((5 + $((5 * ${ncpu})))) && echo -n " distribfold"
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
