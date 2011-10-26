# New ports collection makefile for:	spatialindex
# Date created:				15 June 2008
# Whom:					Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	spatialindex
PORTVERSION=	1.7.0
CATEGORIES=	devel
MASTER_SITES=	http://download.osgeo.org/libspatialindex/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A General Framework for Developing Spatial Indices

USE_AUTOTOOLS=	libtool:env
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
