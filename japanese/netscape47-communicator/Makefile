# New ports collection makefile for: Netscape browser with Japanese resources
# Version required:	4.5
# Date created:		13 Mar 1998
# Whom:			sada
#
# $Id$
#

#MAINTAINER=	sada@FreeBSD.ORG

RUN_DEPENDS?= \
	${PREFIX}/bin/communicator-4.5:${PORTSDIR}/www/netscape45-communicator \
	${FONT_DEPEND}

FILESDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg/PLIST
MASTERDIR=	${.CURDIR}/../netscape4-communicator

BROWSER_VERSION= 4.5
FILES_DIR=	${MASTERDIR}/files
JAPANIZE_KIT=	communicator-ja-euc-v45-export.generic-generic-generic.tar.gz
NSUBDIR=	netscape-4.5

.include "${MASTERDIR}/Makefile"
