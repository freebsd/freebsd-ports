# $FreeBSD$
#
# Include CPE information in package manifest as a CPE 2.3 formatted
# string.  See http://scap.nist.gov/specifications/cpe/ for details.
#
# CPE_PART		Defaults to "a" for "application".
# CPE_VENDOR		Defaults to same as ${CPE_PRODUCT} (below).
# CPE_PRODUCT		Defaults to ${PORTNAME}.
# CPE_VERSION		Defaults to ${PORTVERSION}.
# CPE_UPDATE		Defaults to empty.
# CPE_EDITION		Defaults to empty.
# CPE_LANG		Defaults to empty.
# CPE_SW_EDITION	Defaults to empty.
# CPE_TARGET_SW		Defaults to the operating system name and version
# CPE_TARGET_HW		Defaults to x86 for i386, x64 for amd64, and
#			otherwise ${ARCH}.
# CPE_OTHER		Defaults to ${PORTREVISION} if non-zero.
#
# MAINTAINER: ports-secteam@FreeBSD.org

.if !defined(_INCLUDE_USES_CPE_MK)
_INCLUDE_USES_CPE_MK=    yes

CPE_PART	?= a
CPE_PRODUCT	?= ${PORTNAME:tl}
CPE_VENDOR	?= ${CPE_PRODUCT}
CPE_VERSION	?= ${PORTVERSION:tl}
CPE_UPDATE	?=
CPE_EDITION	?=
CPE_LANG	?=
CPE_SW_EDITION	?=
CPE_TARGET_SW	?= ${OPSYS:tl}${OSREL:C/\..*//}
CPE_TARGET_HW	?= ${ARCH:S/i386/x86/:S/amd64/x64/}
CPE_OTHER	?= ${PORTREVISION:N0}
_CPE_STR	 = cpe:2.3:${CPE_PART}:${CPE_VENDOR}:${CPE_PRODUCT}:${CPE_VERSION}:${CPE_UPDATE}:${CPE_EDITION}:${CPE_LANG}:${CPE_SW_EDITION}:${CPE_TARGET_SW}:${CPE_TARGET_HW}:${CPE_OTHER}
CPE_STR		?= ${_CPE_STR:C/:+$//}

PKG_NOTES	+= cpe
PKG_NOTE_cpe	 = ${CPE_STR}

.endif
