# Created by: marino@FreeBSD.org
# $FreeBSD$

PORTNAME=	copperspice
PORTVERSION=	1.0.4
CATEGORIES=	graphics
MASTER_SITES=	http://download.copperspice.com/copperspice/source/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Modern cross-platform C++ GUI library (derived from Qt 4.8)

LICENSE=	LGPL21

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
LIB_DEPENDS=	libaudio.so:${PORTSDIR}/audio/nas \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		compiler:c++11-lib gmake iconv libtool pkgconfig \
		tar:bz2
USE_XORG=	ice sm x11 xcursor xext xi xinerama xrandr
USE_GNOME=	glib20
USE_GL=		gl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/glib-2.0 \
		-I${LOCALBASE}/lib/glib-2.0/include \
		-I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${ICONV_PREFIX}/lib ${ICONV_LIB} -L${LOCALBASE}/lib

CONFIGURE_ARGS=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL="${INSTALL}" \
		OSTYPE=FREEBSD
CONFIGURE_ENV=	ZLIB_LIBS="-lz" ZLIB_CFLAGS="-I/usr/include -L/usr/lib"
MAKE_ENV=	INSTALL_STRIP_PROGRAM="${INSTALL_PROGRAM}"
PLIST_SUB=	SHORT_VER=0 LONG_VER=0.0.0

MAKE_JOBS_UNSAFE=	yes
WITH_OPENSSL_PORT=	yes

BROKEN_FreeBSD_8=	error: 'to_string' is not a member of 'std'
BROKEN_FreeBSD_9=	error: 'to_string' is not a member of 'std'
BROKEN_i386=		qx11embed_x11.cpp:470:20: non-constant-expression\
			cannot be narrowed from type 'unsigned int' to 'long'\
			in initializer list [-Wc++11-narrowing]

#OPTIONS_DEFINE=	OPENSSL #MYSQL PGSQL
#OPTIONS_DEFAULT=	OPENSSL
#OPENSSL_USE=	OPENSSL
#.include <bsd.port.options.mk>

post-extract:
	${MKDIR} ${WRKSRC}/mkspecs/bsd-g++

post-patch:
	${REINPLACE_CMD} -e 's|@INSTALL@|${INSTALL}|g' \
		${WRKSRC}/src/webkit/Makefile.in

post-configure:
	${REINPLACE_CMD} -e '/^hardcode_libdir_flag/ \
		s|spec=.*|spec="-Wl,-rpath,${LOCALBASE}/lib"|' \
		${WRKSRC}/libtool

.include <bsd.port.mk>
