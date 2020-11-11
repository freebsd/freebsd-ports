#!/bin/sh
# MAINTAINER: rust@FreeBSD.org
# $FreeBSD$
set -eu
set -o pipefail

if [ "${OPSYS}" != FreeBSD ] || [ "${OSVERSION}" -lt 1200000 ]; then
	exit 0
fi

cat <<EOF | ${CC} -o "${WRKDIR}/compat11_canary" -xc -
#include <sys/syscall.h>
#include <errno.h>
#include <unistd.h>

int
main(void)
{
	return syscall(SYS_freebsd11_mknod, "", 0, 0) < 0 && errno == ENOSYS;
}
EOF
# Canary might be aborted with SIGSYS
ulimit -c 0
if ! "${WRKDIR}/compat11_canary"; then
	echo "=> Sanity check failed: kernel is missing COMPAT_FREEBSD11"
	echo "=> Aborting build"
	exit 1
fi
