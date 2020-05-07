# $FreeBSD$

PORTNAME=	libavif
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Library for encoding and decoding .avif files

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake compiler:c11 jpeg localbase:ldflags pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	AOMediaCodec
CMAKE_ON=	AVIF_BUILD_APPS

OPTIONS_DEFINE=	AOM DAV1D RAV1E
OPTIONS_DEFAULT=AOM DAV1D

AOM_DESC=		AV1 encoding/decoding via libaom
AOM_LIB_DEPENDS=	libaom.so:multimedia/aom
AOM_CMAKE_BOOL=		AVIF_CODEC_AOM

DAV1D_DESC=		AV1 decoding via libdav1d
DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d
DAV1D_CMAKE_BOOL=	AVIF_CODEC_DAV1D

RAV1E_DESC=		AV1 encoding via librav1e
RAV1E_LIB_DEPENDS=	librav1e.so:multimedia/librav1e
RAV1E_CMAKE_BOOL=	AVIF_CODEC_RAV1E

.include <bsd.port.mk>
