# New ports collection makefile for: Netscape browser with Japanese resources
# Date created:		24 Mar 2000
# Whom:			imura@FreeBSD.org
#
# $FreeBSD$
#

RUN_DEPENDS=	${PREFIX}/bin/${BROWSER_ARC}-${BROWSER_VERSION}:${PORTSDIR}/www/linux-netscape47-${BROWSER}
RUN_DEPENDS+=	/compat/linux/usr/share/locale/ja_JP:${PORTSDIR}/japanese/linux_locale

MAINTAINER=	imura@FreeBSD.org

BROWSER_ARC=	${BROWSER}-linux
MASTERDIR_LINUX= ${.CURDIR}/../linux-netscape47-communicator
NSUBDIR=	lib/netscape-linux
START_SCRIPT=	${MASTERDIR_LINUX}/files/start.sh.in

.include "${.CURDIR}/../netscape47-communicator/Makefile"
