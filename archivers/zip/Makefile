# New ports collection makefile for:    zip (without encryption)
# Version required:     2.1
# Date created:         22 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.8 1996/11/18 13:56:21 asami Exp $
#

DISTNAME=       zip21
PKGNAME=        zip-2.1
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.cdrom.com/pub/infozip/src/
EXTRACT_SUFX=   .zip

MAINTAINER=     ache@FreeBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -oq
NO_WRKSUBDIR=   yes
MAKEFILE=       unix/Makefile
ALL_TARGET=     generic
MAN1=		zip.1 zipgrep.1

.include <bsd.port.mk>
