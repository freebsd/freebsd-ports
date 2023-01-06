PORTNAME=	libheif
DISTVERSION=	1.14.1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/strukturag/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	ISO/IEC 23008-12:2017 HEIF file format de- and encoder
WWW=		https://github.com/strukturag/libheif

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang cpe gettext-runtime gnome \
		localbase:ldflags pkgconfig shared-mime-info
CPE_VENDOR=	struktur
USE_GNOME=	gdkpixbuf2 glib20
USE_LDCONFIG=	yes
PLIST_SUB=	LIB_VER=${DISTVERSION}

OPTIONS_DEFINE=		AOM DAV1D EXAMPLES LIBDE265 SVTAV1 RAV1E X265
OPTIONS_DEFAULT=	AOM DAV1D LIBDE265 SVTAV1 X265
OPTIONS_SUB=	yes

AOM_DESC=		AV1 encoding/decoding via libaom
DAV1D_DESC=		Build dav1e decoder
LIBDE265_DESC=		Use libde265 (support for HEVC decoding)
SVTAV1_DESC=		Build svt-av1 encoder
RAV1E_DESC=		Build rav1e encoder
X265_DESC=		Use x265 (support for HEVC encoding)

AOM_LIB_DEPENDS=	libaom.so:multimedia/aom
AOM_CMAKE_BOOL=		WITH_AOM_ENCODER WITH_AOM_DECODER

DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d
DAV1D_CMAKE_BOOL=	WITH_DAV1D

EXAMPLES_LIB_DEPENDS=	libpng16.so:graphics/png
EXAMPLES_USES=		jpeg
EXAMPLES_CMAKE_BOOL=	WITH_EXAMPLES

LIBDE265_LIB_DEPENDS=	libde265.so:multimedia/libde265
LIBDE265_CMAKE_BOOL=	WITH_LIBDE265

SVTAV1_LIB_DEPENDS=	libSvtAv1Enc.so:multimedia/svt-av1
SVTAV1_CMAKE_BOOL=	WITH_SvtEnc

RAV1E_LIB_DEPENDS=	librav1e.so:multimedia/librav1e
RAV1E_CMAKE_BOOL=	WITH_RAV1E

X265_LIB_DEPENDS=	libx265.so:multimedia/x265
X265_CMAKE_BOOL=	WITH_X265

.include <bsd.port.mk>
