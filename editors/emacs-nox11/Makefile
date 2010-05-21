# Ports collection makefile for:  emacs-devel
# Date created:			  Sep 07 2008
# Whom:				  phoffman@proper.com
#
# $FreeBSD$
#

WITHOUT_X11=    yes
PKGNAMESUFFIX=	-nox11

MASTERDIR=      ${.CURDIR}/../emacs
LATEST_LINK=	emacs-nox11

.if ${OSVERSION} < 700000 && defined(WITH_DBUS)
BROKEN= Does not currently build with dbus support
.endif

.include "${MASTERDIR}/Makefile"
