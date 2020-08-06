# $FreeBSD$

PORTNAME=	libavif
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
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

OPTIONS_DEFINE=	AOM DAV1D PIXBUF RAV1E
OPTIONS_DEFAULT=AOM DAV1D PIXBUF
OPTIONS_SUB=	yes

AOM_DESC=		AV1 encoding/decoding via libaom
AOM_LIB_DEPENDS=	libaom.so:multimedia/aom
AOM_CMAKE_BOOL=		AVIF_CODEC_AOM

DAV1D_DESC=		AV1 decoding via libdav1d
DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d
DAV1D_CMAKE_BOOL=	AVIF_CODEC_DAV1D

PIXBUF_USES=		gnome
PIXBUF_USE=		GNOME=gdkpixbuf2
PIXBUF_CMAKE_BOOL=	AVIF_BUILD_GDK_PIXBUF
PIXBUF_CFLAGS=		-Wno-error=cast-qual # https://github.com/AOMediaCodec/libavif/issues/251

RAV1E_DESC=		AV1 encoding via librav1e
RAV1E_LIB_DEPENDS=	librav1e.so:multimedia/librav1e
RAV1E_CMAKE_BOOL=	AVIF_CODEC_RAV1E

# XXX Drop after misc/shared-mime-info is updated to 2.0
PIXBUF_USES+=		shared-mime-info
PIXBUF_PLIST_FILES+=	share/mime/packages/${PORTNAME}.xml
do-install-PIXBUF-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${FILESDIR}/mime.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages/${PORTNAME}.xml

.include <bsd.port.mk>
