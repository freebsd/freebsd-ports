# New ports collection makefile for: Netscape browser with Korean resources
# Date created:		14 Jun 1999
# Whom:			cjh@kr.freebsd.org
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../netscape4-communicator

MAINTAINER=	cjh@kr.freebsd.org

RUN_DEPENDS=	${PREFIX}/bin/${BROWSER}-${BROWSER_VERSION}:${PORTSDIR}/www/netscape47-${BROWSER}

FILESDIR?=	${.CURDIR}/files


BROWSER_CMD=	ko-${BROWSER}-47
BROWSER_VERSION=	4.72
NETHELP=        nethelp-v451
KOREAN_KIT=	netscape-korean-kit-v472.20000302

.include "${MASTERDIR}/Makefile"
