# New ports collection makefile for:    zip (without encryption)
# Version required:     2.1
# Date created:         22 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1995/04/24 10:58:57 asami Exp $
#

DISTNAME=       zip21
PKGNAME=        zip-2.1
CATEGORIES+=	archivers
MASTER_SITES=   ftp://quest.jpl.nasa.gov/pub/
EXTRACT_SUFX=   .zip

MAINTAINER=     ache@FreeBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -oq
NO_WRKSUBDIR=   yes
MAKEFILE=       unix/Makefile
ALL_TARGET=     generic

.include <bsd.port.mk>
