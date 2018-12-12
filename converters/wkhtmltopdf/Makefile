# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wkhtmltopdf
PORTVERSION=	0.12.5
PORTREVISION=	2
CATEGORIES=	converters

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Convert HTML (or live webpages) to PDF or image

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to build: error: cast from pointer to smaller type loses information
BROKEN_armv6=		fails to build: error: Not supported ARM architecture
BROKEN_armv7=		fails to build: error: invalid operand for instruction
BROKEN_mips64=		fails to link: undefined reference to __sync_add_and_fetch_4
BROKEN_SSL=		openssl111
BROKEN_SSL_REASON_openssl111=	member access into incomplete type 'SSL_CIPHER' (aka 'ssl_cipher_st')

RUN_DEPENDS=	webfonts>=0:x11-fonts/webfonts
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		compiler:c++11-lang gmake iconv jpeg perl5 pkgconfig ssl:build
USE_XORG=	x11 xext xrender
USE_PERL5=	build
USE_LDCONFIG=	yes
USE_GITHUB=	yes
WKQT_TAGNAME=	5db36ec
GH_TUPLE=	${PORTNAME}:qt:${WKQT_TAGNAME}:qt
USE_CXXSTD=	gnu++98
HAS_CONFIGURE=	yes

PATCH_WRKSRC=		${WRKSRC}/qt
CONFIGURE_WRKSRC=	${WRKSRC}/build/qt
BUILD_WRKSRC=		${WRKSRC}/build/qt
INSTALL_WRKSRC=		${WRKSRC}/build/app

CONFIGURE_SCRIPT=	../../qt/configure
CONFIGURE_ARGS=	-prefix ${WRKSRC}/build/qt \
	-opensource -confirm-license -fast -release -static \
	-graphicssystem raster -webkit -exceptions -xmlpatterns -system-zlib \
	-system-libpng -system-libjpeg -no-libmng -no-libtiff -no-stl \
	-no-accessibility -no-qt3support -no-phonon -no-phonon-backend \
	-no-opengl -no-declarative -no-script -no-scripttools \
	-no-sql-ibase -no-sql-mysql -no-sql-odbc -no-sql-psql \
	-no-sql-sqlite -no-sql-sqlite2 -no-mmx -no-3dnow -no-sse -no-sse2 \
	-no-multimedia -nomake demos -nomake docs -nomake examples \
	-nomake tools -nomake tests -nomake translations -xrender -largefile \
	-iconv -openssl -no-rpath -no-dbus -no-nis -no-cups -no-pch \
	-no-gtkstyle -no-nas-sound -no-sm -no-xshape -no-xinerama -no-xcursor \
	-no-xfixes -no-xrandr -no-mitshm -no-xinput -no-xkb -no-glib \
	-no-gstreamer -D ENABLE_VIDEO=0 -no-openvg -no-xsync \
	-no-audio-backend -no-sse3 -no-ssse3 -no-sse4.1 -no-sse4.2 -no-avx \
	-no-neon

MAKE_ARGS=	INSTALL_ROOT="${STAGEDIR}${PREFIX}"

pre-patch:
	${RMDIR} ${WRKSRC}/qt
	${LN} -s ../qt-${WKQT_TAGNAME} ${WRKSRC}/qt

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|/usr/X11R6/include|${LOCALBASE}/include/X11|g' \
		-e 's|/usr/X11R6/lib|${LOCALBASE}/lib|g' \
		${PATCH_WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%GCC_DEFAULT%%|${GCC_DEFAULT}|g' \
		${PATCH_WRKSRC}/mkspecs/common/gcc-base.conf
	${REINPLACE_CMD} -e "s|gcc|${CC}|g" -e "s|g++|${CXX}|g" \
		${PATCH_WRKSRC}/mkspecs/common/g++-base.conf
	${REINPLACE_CMD} -e "s|share/man|man|g" \
		${WRKSRC}/src/image/image.pro \
		${WRKSRC}/src/pdf/pdf.pro
	${ECHO} 'LIBS+= -lcrypto' >>${WRKSRC}/src/image/image.pro
	${ECHO} 'LIBS+= -lcrypto' >>${WRKSRC}/src/pdf/pdf.pro
	${MKDIR} ${WRKSRC}/build/app ${WRKSRC}/build/qt \
		${WRKSRC}/build/wkhtmltox

post-build:
	cd ${WRKSRC}/build/app && ${SETENV} ${MAKE_ENV} \
		../qt/bin/qmake ../../wkhtmltopdf.pro && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS:C,^${DESTDIRNAME}=.*,,g} \
		${ALL_TARGET}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/wkhtmltoimage \
		${STAGEDIR}${PREFIX}/bin/wkhtmltopdf \
		${STAGEDIR}${PREFIX}/lib/libwkhtmltox.so.${PORTVERSION}

.include <bsd.port.mk>
