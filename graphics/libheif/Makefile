PORTNAME=	libheif
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.0-62
DISTVERSIONSUFFIX=	-g0082fea
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	makc@FreeBSD.org
COMMENT=	ISO/IEC 23008-12:2017 HEIF file format de- and encoder

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang cpe gettext-runtime gnome \
		localbase:ldflags pkgconfig shared-mime-info
CPE_VENDOR=	struktur
USE_GNOME=	gdkpixbuf2 glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	strukturag

OPTIONS_DEFINE=		AOM DAV1D EXAMPLES LIBDE265 RAV1E X265
OPTIONS_DEFAULT=	AOM DAV1D LIBDE265 X265

AOM_DESC=		AV1 encoding/decoding via libaom
DAV1D_DESC=		Build dav1e decoder
LIBDE265_DESC=		Use libde265 (support for HEVC decoding)
RAV1E_DESC=		Build rav1e encoder
X265_DESC=		Use x265 (support for HEVC encoding)

AOM_LIB_DEPENDS=	libaom.so:multimedia/aom
AOM_CMAKE_BOOL=		WITH_AOM

DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d
DAV1D_CMAKE_BOOL=	WITH_DAV1D

EXAMPLES_LIB_DEPENDS=	libpng16.so:graphics/png
EXAMPLES_USES=		jpeg
EXAMPLES_CMAKE_BOOL=	WITH_EXAMPLES

LIBDE265_LIB_DEPENDS=	libde265.so:multimedia/libde265
LIBDE265_CMAKE_BOOL=	WITH_LIBDE265

RAV1E_LIB_DEPENDS=	librav1e.so:multimedia/librav1e
RAV1E_CMAKE_BOOL=	WITH_RAV1E

X265_LIB_DEPENDS=	libx265.so:multimedia/x265
X265_CMAKE_BOOL=	WITH_X265

.include <bsd.port.mk>
