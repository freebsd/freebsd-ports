# New ports collection makefile for: Netscape browser with Japanese resources
# Version required:	4.5
# Date created:		13 Mar 1998
# Whom:			sada
#
# $Id: Makefile,v 1.2 1998/12/27 09:09:50 asami Exp $
#

MASTERDIR=	${.CURDIR}/../netscape4-communicator

MAINTAINER=	sada@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/bin/${BROWSER}-${BROWSER_VERSION}:${PORTSDIR}/www/netscape45-${BROWSER} \
		${FONT_DEPEND}

FILESDIR=	${.CURDIR}/files

BROWSER_CMD=	ja-${BROWSER}-45
BROWSER_VERSION= 4.5
JAPANIZE_KIT=	communicator-ja-euc-v45-export.generic-generic-generic.tar.gz
NSUBDIR=	netscape-4.5
PORTKIT=	ja-netscape45-portkit.1998.1228.tar.gz

.include "${MASTERDIR}/Makefile"
