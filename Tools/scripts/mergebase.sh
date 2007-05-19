#!/bin/sh
# rev 6
# $FreeBSD$
#

X11BASE="/usr/X11R6"
LOCALBASE="/usr/local"

BACKUPDIR="/usr/tmp/mergebase"
BACKUPFILE="oldx11base.`date -j +%Y%m%d.%H%M%S`.tar"

echo "This script will attempt to backup ${X11BASE} into"
echo "${BACKUPDIR}/${BACKUPFILE} and then move the"
echo "contents onto ${LOCALBASE}. It will then replace ${X11BASE}"
echo "with a symbolic link, pointing to ${LOCALBASE}. After that,"
echo "the script will attempt to change some settings in /etc"
echo "that by default point to both ${X11BASE} and ${LOCALBASE}"
echo "to remove references to ${X11BASE}; specifically, the files"
echo "that could get altered are /etc/periodic.conf"
echo "/etc/manpath.config /etc/rc.conf."
echo
echo "Be advised that this script expects default environment,"
echo "notably it assumes that you have not changed \$X11BASE and"
echo "\$LOCALBASE variables from their default values and that"
echo "${X11BASE} is regular directory and not separate mount."
echo
echo "If these assumptions are not correct, either edit this script"
echo "to change \$X11BASE \$LOCALBASE and/or \$BACKUPDIR values or"
echo "do the merge by hand (perhaps using this script as a rough guide)."
echo

read -p "Enter 'yes' to continue, anything else will exit script: " answer
if [ "${answer}x" != "yesx" ]; then
	echo "Aborted."
	exit 1
fi

mrg_done=0
mpath_done=0
ppath_done=0
rcconf_done=0

if [ -d ${X11BASE} -a ! -L ${X11BASE} ]; then
	lbase_list=`mktemp -t mergebase` || exit 1
	xbase_list=`mktemp -t mergebase` || exit 1
	common_list=`mktemp -t mergebase` || exit 1
	(cd ${LOCALBASE} && find . ! -type d | sort >${lbase_list})
	(cd ${X11BASE} && find . ! -type d | sort >${xbase_list})
	comm -1 -2 ${lbase_list} ${xbase_list} >${common_list}
	if [ -s ${common_list} ]; then
		echo "CONFLICTING FILES:"
		cat ${common_list}
		echo
		echo -n "Files that exist both in ${LOCALBASE} and ${X11BASE} "
		echo -n "have been found as shown above. Merging will not "
		echo "continue."
		echo -n "While some such files are safe to remove as they "
		echo -n "will be regenerated (like ${X11BASE}/man/whatis), "
		echo -n "some you might want to move away somewhere safe, "
		echo "and some might point to conflicts in ports."
		echo -n "For this script to continue, you need to either "
		echo -n "move these files away from ${X11BASE} or delete them. "
		echo -n "If you don't know what to do about a particular file, "
		echo "ask on x11@FreeBSD.org mailing list."
		echo "The list is saved in ${common_list}."
		rm ${lbase_list} ${xbase_list}
		exit 1
	fi
	rm ${lbase_list} ${xbase_list} ${common_list}

	echo "==> Creating backup of X11BASE in ${BACKUPDIR}..."
	mkdir -p ${BACKUPDIR}
	tar -cvf ${BACKUPDIR}/${BACKUPFILE} -C ${X11BASE} .
	if [ $? -ne 0 ]; then
		echo "Backup failed."
		exit 1
	fi

	echo "==> Merging X11BASE into LOCALBASE..."
	errfile=`mktemp -t mergebase` || exit 1
	tar -xpkf ${BACKUPDIR}/${BACKUPFILE} -C ${LOCALBASE} 2>${errfile}
	if [ `grep -Ev 'File exists$|Error exit delayed from previous errors' ${errfile} | wc -c` -ne 0 ]; then
		echo "Merge failed. See ${errfile} for more information."
		exit 1
	fi
	rm ${errfile}

	echo "==> Creating compatibility symlink ${X11BASE} -> ${LOCALBASE}..."
	rm -rf ${X11BASE}
	ln -s ${LOCALBASE} ${X11BASE}
	mrg_done=1
fi

# periodic.conf
local_periodic=`. /etc/defaults/periodic.conf && source_periodic_confs ; echo ${local_periodic}`
for lp in ${local_periodic}; do
	if (expr ${lp} : "^${X11BASE}" >/dev/null); then
		continue
	else
		new_periodic="${new_periodic} ${lp}"
	fi
done
if [ "${local_periodic}x" != "${new_periodic## }x" ]; then
	echo "==> Removing ${X11BASE}/etc/periodic from periodic setup..."
	echo "# added by mergebase.sh" >> /etc/periodic.conf
	echo "local_periodic=\"${new_periodic## }\"" >> /etc/periodic.conf
	ppath_done=1
fi

# manpath.config
if (PATH="/sbin:/bin:/usr/sbin:/usr/bin" manpath -q | grep -q "${X11BASE}");then
	echo "==> Removing ${X11BASE}/man from MANPATH..."
	sed -i ".bak.mergebase" -e "s,^[^#]*${X11BASE}.*$,#&," \
	    /etc/manpath.config
	mpath_done=1
fi

# rc.conf
rcdirs=`. /etc/defaults/rc.conf && source_rc_confs && echo ${local_startup}`
for rd in ${rcdirs}; do
	if (expr ${rd} : "${X11BASE}" >/dev/null); then
		continue
	else
		new_rcdirs="${new_rcdirs} ${rd}"
	fi
done
if [ "${rcdirs}x" != "${new_rcdirs## }x" ]; then
	echo "==> Removing ${X11BASE} from rc sequence..."
	echo "# added by mergebase.sh" >> /etc/rc.conf
	echo "local_startup=\"${new_rcdirs## }\"" >> /etc/rc.conf
	rcconf_done=1
fi


if [ ${mrg_done} -eq 1 ]; then
	echo
	echo "The contents of ${X11BASE} has been backed up in ${BACKUPDIR}."
	echo "Remove it once you are sure nothing has been lost in merge."
fi
if [ ${ppath_done} -eq 1 ]; then
	echo
	echo "${X11BASE} has been removed from periodic setup. You might"
	echo "want to review /etc/periodic.conf for changes."
fi
if [ ${mpath_done} -eq 1 ]; then
	echo
	echo "${X11BASE} has been commented out in /etc/manpath.config."
	echo "You might want to review the changes there."
fi
if [ ${rcconf_done} -eq 1 ]; then
	echo
	echo "${X11BASE} has been removed from system initialization (rc)."
	echo "You might want to check /etc/rc.conf changes."
fi

echo "Done."
