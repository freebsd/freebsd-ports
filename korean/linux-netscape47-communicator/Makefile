# New ports collection makefile for: Netscape browser with Korean resources
# Date created:		25 Jun 2000
# Whom:			cjh@FreeBSD.org
#
# $FreeBSD$
#

RUN_DEPENDS=	${PREFIX}/bin/${BROWSER_ARC}-${BROWSER_VERSION}:${PORTSDIR}/www/linux-netscape47-${BROWSER}
RUN_DEPENDS+=	/compat/linux/usr/share/locale/ko/LC_MESSAGES/SYS_LC_MESSAGES:${PORTSDIR}/korean/linux_locale

MAINTAINER=	cjh@FreeBSD.org

BROWSER_ARC=    ${BROWSER}-linux
MASTERDIR_LINUX= ${.CURDIR}/../linux-netscape47-communicator
NSUBDIR=	lib/netscape-linux
START_SCRIPT=	${MASTERDIR_LINUX}/files/start.sh.in
# for 4.77, temporary
BROWSER_VERSION=      4.77

post-patch:
	${PATCH} ${PATCH_DIST_ARGS} < ${MASTERDIR_LINUX}/files/patch-aa

.include "${.CURDIR}/../netscape47-communicator/Makefile"
