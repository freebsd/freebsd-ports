PORTNAME=	gimp-jxl-plugin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GIMP plugin to read/write JPEG XL images
WWW=		https://jpeg.org/jpegxl/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC:H:H}/LICENSE

LIB_DEPENDS=	libgegl-0.4.so:graphics/gegl \
		libgimp-2.0.so:graphics/gimp-app \
		libjxl.so:graphics/libjxl \
		libbabl-0.1.so:x11/babl

USES=		cmake compiler:c++11-lang gnome pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtk20
GH_ACCOUNT=	${GH_PROJECT}
GH_PROJECT=	libjxl
WRKSRC_SUBDIR=	plugins/gimp
LDFLAGS+=	-Wl,--as-needed # GIMP deps
PLIST_FILES=	libexec/gimp/2.2/plug-ins/file-jxl/file-jxl

.include <bsd.port.mk>
