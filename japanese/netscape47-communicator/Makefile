# New ports collection makefile for: Netscape browser with Japanese resources
# Version required:	4.5
# Date created:		13 Mar 1998
# Whom:			sada
#
# $Id: Makefile,v 1.3 1998/12/28 16:14:46 sada Exp $
#

MASTERDIR=	${.CURDIR}/../netscape4-communicator

MAINTAINER=	sada@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/bin/${BROWSER}-${BROWSER_VERSION}:${PORTSDIR}/www/netscape45-${BROWSER} \
		${FONT_DEPEND}

FILESDIR?=	${.CURDIR}/files

BROWSER_CMD=	ja-${BROWSER}-45
BROWSER_VERSION= 4.5
JAPANIZE_KIT=	communicator-ja-euc-v45-export.generic-generic-generic.tar.gz
NSUBDIR?=	netscape-4.5

.include "${MASTERDIR}/Makefile"
