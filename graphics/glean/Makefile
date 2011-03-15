# New ports collection makefile for:	glean
# Date created:				12 Dec 2003
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glean
PORTVERSION=	1.0.20030925
PORTREVISION=	5
CATEGORIES=	graphics benchmarks
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	anholt
DISTNAME=	glean-20030925-snap
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of OpenGL conformance tests

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

PLIST_FILES=	bin/glean
WRKSRC=		${WRKDIR}/glean/src
USE_BZIP2=	yes
USE_GL=		glut
USE_GMAKE=	yes
MAKE_ENV+=	GLEAN_ROOT="${WRKDIR}/glean"
ALL_TARGET=	install

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/glean/bin/glean ${PREFIX}/bin

.include <bsd.port.mk>
