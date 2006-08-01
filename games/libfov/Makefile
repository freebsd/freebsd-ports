# New ports collection makefile for:    libfov
# Date created:         12 Jan 2006
# Whom:                 aaron@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libfov
PORTVERSION=	1.0.2
CATEGORIES=	games devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	libfov

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	C  library for calculating fields of view on low resolution rasters

WRKSRC=	${WRKDIR}/${DISTNAME}/fov
INSTALLS_SHLIB=	yes

post-extract:
	@${CP} ${PATCHDIR}/Makefile.bsd ${WRKSRC}/Makefile

.include <bsd.port.mk>
