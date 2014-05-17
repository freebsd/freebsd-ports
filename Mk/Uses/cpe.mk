# $FreeBSD$
#
# Include CPE URI in package manifest.
#
# http://scap.nist.gov/specifications/cpe/
#
# The URI is constructed as follows:
#
# cpe:/part:vendor:product:version:update:edition:lang
#
# Trailing colons are ommitted.
#
# CPE_PART	Defaults to (and should always be) "a" for "application"
# CPE_VENDOR	Defaults to same as ${CPE_PRODUCT} (below)
# CPE_PRODUCT	Defaults to ${PORTNAME}
# CPE_VERSION	Defaults to ${PORTVERSION}
# CPE_UPDATE	Defaults to empty
# CPE_EDITION	Defaults to ~~~freebsd~~, see below
# CPE_LANG	Defaults to empty
#
# Originally, EDITION was an arbitrary string.  In later revisions of
# the CPE specification, it is composed of five tilde-separated fields
# with a leading tilde to distinguish the new syntax from the old.
# The five fields are:
#
# CPE_LEGACY_EDITION	Defaults to empty
# CPE_SW_EDITION	Defaults to empty
# CPE_TARGET_SW		Defaults to "freebsd"
# CPE_TARGET_HW		Defaults to empty (subject to future change)
# CPE_OTHER		Defaults to empty
#
# MAINTAINER: ports-secteam@freebsd.org

.if !defined(_INCLUDE_USES_CPE_MK)
_INCLUDE_USES_CPE_MK=    yes

CPE_PART	?= a
CPE_PRODUCT	?= ${PORTNAME}
CPE_VENDOR	?= ${CPE_PRODUCT}
CPE_VERSION	?= ${PORTVERSION}
CPE_UPDATE	?=
CPE_LEGACY_EDITION	?=
CPE_SW_EDITION	?=
CPE_TARGET_SW	?= freebsd
CPE_TARGET_HW	?=
CPE_OTHER	?=
CPE_EDITION	?= ~${CPE_LEGACY_EDITION}~${CPE_SW_EDITION}~${CPE_TARGET_SW}~${CPE_TARGET_HW}~${CPE_OTHER}
CPE_LANG	?=
_CPE_URI	 = cpe:/${CPE_PART}:${CPE_VENDOR}:${CPE_PRODUCT}:${CPE_VERSION}:${CPE_UPDATE}:${CPE_EDITION}:${CPE_LANG}
CPE_URI		?= ${_CPE_URI:C/:+$//}

PKG_NOTES	+= cpe
PKG_NOTE_cpe	 = ${CPE_URI}

.endif
