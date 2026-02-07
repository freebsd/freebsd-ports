#!/bin/sh
# redundant-opt-files.sh
# Written by John Marino (marino@FreeBSD.org)
#
# This script checks every option file against the default options of
# its port.  If they are identical, it writes the full path of the ports
# option directory (typically in /var/db/ports) to stdout.
# It is typically used by Synth users to identify options files that can
# deleted in order to prevent future configuration check failures.

portsdir=${PORTSDIR:-/usr/ports}
if [ ! -d "${portsdir}" ]; then
   echo "The ${portsdir} ports directory does not exist"
   echo "There is nothing more to do."
   exit
fi

db_dir=$(/usr/bin/make -C ${portsdir}/devel/gmake -V PORT_DBDIR 2>/dev/null)

if [ ! -d "${db_dir}" ]; then
   echo "The ${db_dir} ports option directory does not exist"
   echo "There is nothing more to do."
   exit
fi

catport() {
   local category
   local port
   local workstr=${1#${db_dir}/}
   local words=$(echo ${workstr} | /usr/bin/tr "_" " ");
   for word in ${words}; do
      category=${word}
      break;
   done
   port=${workstr#${category}_}
   echo ${portsdir}/$category/$port
}

identical_options() {
   local origin=$(catport $1)
   if [ ! -d ${origin} ]; then
       # origin no longer exists, list it anyway without testing further
       echo $1
       return
   fi
   local selected_pristine=$(/usr/bin/make -C ${origin} \
   	-V SELECTED_OPTIONS PORT_DBDIR=/dev/null)
   local selected_now=$(/usr/bin/make -C ${origin} -V SELECTED_OPTIONS)
   local deselected_pristine=$(/usr/bin/make -C ${origin} \
   	-V DESELECTED_OPTIONS PORT_DBDIR=/dev/null)
   local deselected_now=$(/usr/bin/make -C ${origin} -V DESELECTED_OPTIONS)
   if [ "${selected_pristine}" = "${selected_now}" -a \
        "${deselected_pristine}" = "${deselected_now}" ]; then
      echo $1
   fi;
}

optdirs=$(/usr/bin/find -s "${db_dir}" -type d -depth 1)

for dossier in ${optdirs}; do
  identical_options ${dossier}
done
