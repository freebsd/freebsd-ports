# Ports collection makefile for:  epm
# Date created:			  20 Nov 2004
# Whom:				  NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epm
PORTVERSION=	3.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     maho/openoffice.org
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
EXTRACT_SUFX=	.tar.bz2

PATCH_DIST_STRIP=       -p2

MAINTAINER=	openoffice@FreeBSD.org
COMMENT=	A free UNIX software/file packaging program

PATCHFILES+=    epm-3.7.patch
PATCH_SITES+=   http://installation.openoffice.org/

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	259
MAN1=		epm.1 epminstall.1 mkepmlist.1 setup.1
MAN5=		epm.list.5 setup.types.5

.include <bsd.port.mk>
