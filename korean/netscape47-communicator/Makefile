# New ports collection makefile for: Netscape browser with Korean resources
# Version required:	4.61
# Date created:		14 Jun 1999
# Whom:			cjh@kr.freebsd.org
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../netscape4-communicator

MAINTAINER=	cjh@kr.freebsd.org

RUN_DEPENDS=	${PREFIX}/bin/${BROWSER}-${BROWSER_VERSION}:${PORTSDIR}/www/netscape46-${BROWSER}

FILESDIR?=	${.CURDIR}/files


BROWSER_CMD=	ko-${BROWSER}-46
BROWSER_VERSION=	4.61
NETHELP=        nethelp-v451
KOREAN_KIT=	netscape-korean-kit-v461.19990804

.include "${MASTERDIR}/Makefile"
