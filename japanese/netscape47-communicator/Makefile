# New ports collection makefile for: Netscape browser with Japanese resources
# Version required:	4.6
# Date created:		13 Mar 1998
# Whom:			sada
#
# $Id: Makefile,v 1.7 1999/05/21 01:11:00 sada Exp $
#

MASTERDIR=	${.CURDIR}/../netscape4-communicator

MAINTAINER=	sada@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/bin/${BROWSER}-${BROWSER_VERSION}:${PORTSDIR}/www/netscape46-${BROWSER}

BROWSER_CMD=	ja-${BROWSER}-46
BROWSER_VERSION=	4.6
JAPANIZE_KIT=	communicator-ja-euc-v46-export.generic-generic-generic.tar.gz
PORTKIT=	ja-netscape-portkit.1999.0521.tar.gz
NETHELP=	nethelp-v451

.include "${MASTERDIR}/Makefile"
