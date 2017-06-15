# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	spatialindex
PORTVERSION=	1.8.5
CATEGORIES=	devel
MASTER_SITES=	http://download.osgeo.org/libspatialindex/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	General Framework for Developing Spatial Indices

LICENSE=	MIT

USES=		gmake libtool pathfix tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libspatialindex*.so.*

.include <bsd.port.mk>
