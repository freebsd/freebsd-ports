#!/bin/sh

set -e
/usr/bin/sed -i.bak "$@"
for x in "${@}" ; do
    if [ -f "${x}" ]; then
	if cmp -s "${x}" "${x}".bak ; then
            if [ ! -z "${REWARNFILE}" ]; then
                echo sed failed: backup file same as original: ${x#${WRKSRC}/} >> ${REWARNFILE}
            fi
        fi
    fi
done
