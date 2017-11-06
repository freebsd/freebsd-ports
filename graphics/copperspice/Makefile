# Created by: marino@FreeBSD.org
# $FreeBSD$

PORTNAME=	copperspice
PORTVERSION=	1.3.2
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://download.copperspice.com/copperspice/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern cross-platform C++ GUI library (derived from Qt 4.8)

LICENSE=	LGPL21

LIB_DEPENDS=	libaudio.so:audio/nas \
		libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libfreetype.so:print/freetype2 \
		libgstbase-0.10.so:multimedia/gstreamer \
		libgstreamer-0.10.so:multimedia/gstreamer \
		libpcre.so:devel/pcre \
		libfontconfig.so:x11-fonts/fontconfig

USES=		compiler:c++11-lib gettext-runtime gmake iconv libtool \
		pkgconfig tar:bz2
USE_XORG=	ice sm x11 xau xcb xcursor xdamage xdmcp xext xfixes xi \
		xinerama xrandr xrender xt xxf86vm
USE_GNOME=	glib20 libxml2
USE_GL=		gl
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/glib-2.0 \
		-I${LOCALBASE}/lib/glib-2.0/include \
		-I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${ICONV_PREFIX}/lib ${ICONV_LIB} -L${LOCALBASE}/lib

OVERRIDE_INS=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL="${INSTALL}"
CONFIGURE_ARGS=	${OVERRIDE_INS}
MAKE_ARGS=	${OVERRIDE_INS}
PLIST_SUB=	LONG_VER=1.3

BROKEN_i386=		qx11embed_x11.cpp:470:20: non-constant-expression\
			cannot be narrowed from type 'unsigned int' to 'long'\
			in initializer list [-Wc++11-narrowing]
NOT_FOR_ARCHS=		aarch64 armv6 powerpc64
NOT_FOR_ARCHS_REASON=	fails to build: Unable to detect architecture, please update

post-patch:
	# fix something wrong with v1.3.2 generatior
	@${REINPLACE_CMD} -e '/config.status:/ s/:.*/:/' ${WRKSRC}/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e '/^hardcode_libdir_flag/ \
		s|spec=.*|spec="-Wl,-rpath,${LOCALBASE}/lib"|' \
		${WRKSRC}/libtool

.include <bsd.port.mk>
