# New ports collection makefile for: Netscape browser with Japanese resources
# Version required:	4.6*
# Date created:		13 Mar 1998
# Whom:			sada
#
# $Id: Makefile,v 1.10 1999/06/24 20:10:50 sada Exp $
#

MASTERDIR=	${.CURDIR}/../netscape4-communicator

MAINTAINER=	sada@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/bin/${BROWSER}-${BROWSER_VERSION}:${PORTSDIR}/www/netscape46-${BROWSER}

FILESDIR=	${.CURDIR}/../netscape46-communicator/files
PATCHDIR=	${.CURDIR}/../netscape46-communicator/patches

BROWSER_CMD=	ja-${BROWSER}-46
BROWSER_VERSION=	4.61
JAPANIZE_KIT=	communicator-ja-euc-v461-export.generic-generic-generic.tar.gz
NETHELP=	nethelp-v451

.include "${MASTERDIR}/Makefile"
