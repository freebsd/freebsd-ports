# $FreeBSD$

PORTNAME=	libheif
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=		freebsd@sebastiansteinmetz.ch
COMMENT=		Libheif is an ISO/IEC 23008-12:2017 HEIF file format de- and encoder

LICENSE=		LGPL3+
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING

LIB_DEPENDS=	libdav1d.so:multimedia/dav1d \
		librav1e.so:multimedia/librav1e

USES=			cmake compiler:c++11-lang gettext-runtime gnome localbase:ldflags pkgconfig
USE_GNOME=		gdkpixbuf2 glib20
USE_LDCONFIG=		yes

CMAKE_OFF=		WITH_EXAMPLES

USE_GITHUB=		yes
GH_ACCOUNT=		strukturag

OPTIONS_DEFINE=			AOM LIBDE265 X265
OPTIONS_DEFAULT=		AOM LIBDE265 X265
OPTIONS_SUB=			yes

AOM_DESC=			AV1 encoding/decoding via libaom
AOM_CMAKE_BOOL=			WITH_AOM
AOM_LIB_DEPENDS=		libaom.so:multimedia/aom

LIBDE265_DESC=			Use libde265 (support for HEVC decoding)
LIBDE265_CMAKE_BOOL=		WITH_LIBDE265
LIBDE265_LIB_DEPENDS=		libde265.so:multimedia/libde265

X265_DESC=			Use x265 (support for HEVC encoding)
X265_CMAKE_BOOL=		WITH_X265
X265_LIB_DEPENDS=		libx265.so:multimedia/x265

.include <bsd.port.mk>
