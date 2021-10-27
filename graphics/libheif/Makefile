PORTNAME=	libheif
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
PORTREVISION=	4
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	b7caef96e012f6e516fee2e50a836b07b7c5a8fc.patch:-p1 \
		7976e1858a857e33200cd33d01689fd040de6d3d.patch:-p1

MAINTAINER=	freebsd@sebastiansteinmetz.ch
COMMENT=	ISO/IEC 23008-12:2017 HEIF file format de- and encoder

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang cpe gettext-runtime gnome \
		localbase:ldflags pkgconfig
CPE_VENDOR=	struktur
USE_GNOME=	gdkpixbuf2 glib20
USE_LDCONFIG=	yes

CMAKE_OFF=	WITH_EXAMPLES

USE_GITHUB=	yes
GH_ACCOUNT=	strukturag

OPTIONS_DEFINE=		AOM DAV1D LIBDE265 RAV1E X265
OPTIONS_DEFAULT=	AOM DAV1D LIBDE265 RAV1E X265
OPTIONS_SUB=		yes

AOM_DESC=		AV1 encoding/decoding via libaom
AOM_CMAKE_BOOL=		WITH_AOM
AOM_LIB_DEPENDS=	libaom.so:multimedia/aom

DAV1D_DESC=		Build dav1e decoder
DAV1D_CMAKE_BOOL=	WITH_DAV1D
DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d

LIBDE265_DESC=		Use libde265 (support for HEVC decoding)
LIBDE265_CMAKE_BOOL=	WITH_LIBDE265
LIBDE265_LIB_DEPENDS=	libde265.so:multimedia/libde265

RAV1E_DESC=		Build rav1e encoder
RAV1E_CMAKE_BOOL=	WITH_RAV1E
RAV1E_LIB_DEPENDS=	librav1e.so:multimedia/librav1e

X265_DESC=		Use x265 (support for HEVC encoding)
X265_CMAKE_BOOL=	WITH_X265
X265_LIB_DEPENDS=	libx265.so:multimedia/x265

.include <bsd.port.mk>
