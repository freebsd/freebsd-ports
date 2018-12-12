# Created by: marcus@FreeBSD.org
# $FreeBSD$

PORTNAME=	poppler
PORTVERSION=	0.57.0
PORTREVISION=	2
CATEGORIES=	graphics print
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	PDF rendering library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfontconfig.so:x11-fonts/fontconfig \
		liblcms2.so:graphics/lcms2 \
		libfreetype.so:print/freetype2 \
		libnss3.so:security/nss \
		libnspr4.so:devel/nspr
RUN_DEPENDS=	poppler-data>0:graphics/poppler-data

USES=		compiler:c++11-lang cpe gmake jpeg libtool localbase pathfix pkgconfig tar:xz
CPE_VENDOR=	freedesktop
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-zlib \
		--enable-xpdf-headers \
		--disable-libnss \
		--disable-gtk-test \
		--without-html-dir \
		--disable-static \
		--enable-libnss

INSTALL_TARGET=	install-strip

.if !defined(SLAVEPORT)
PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	CAIRO CURL OPENJPEG
OPTIONS_DEFAULT=CAIRO OPENJPEG

USES+=		iconv
.endif

.include <bsd.port.options.mk>

.if defined(SLAVEPORT)
PORTSCOUT=	ignore:1
LIB_DEPENDS+=	libpoppler.so:graphics/poppler

.if ${SLAVEPORT}==glib
CONFIGURE_ARGS+=--enable-poppler-glib --enable-introspection=yes
USE_GNOME+=	cairo glib20 introspection:build
BUILD_WRKSRC=	${WRKSRC}/glib
INSTALL_WRKSRC=	${WRKSRC}/glib
.else
CONFIGURE_ARGS+=--disable-poppler-glib
.endif

.if ${SLAVEPORT}==qt4
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

CONFIGURE_ARGS+=--enable-poppler-qt4
CONFIGURE_ENV+=	MOCQT4=${MOC}
USES+=		qt:4
USE_QT=		gui corelib xml qtestlib moc_build
BUILD_WRKSRC=	${WRKSRC}/qt4
INSTALL_WRKSRC=	${WRKSRC}/qt4
.else
CONFIGURE_ARGS+=--disable-poppler-qt4
.endif

.if ${SLAVEPORT}==qt5
CONFIGURE_ARGS+=--enable-poppler-qt5
CONFIGURE_ENV+=	MOCQT5=${MOC}
USES+=		qt:5
USE_QT=		core gui widgets xml buildtools_build testlib_build
# Qt from 5.7.0 on requires c++11.
USE_CXXSTD=	c++11
BUILD_WRKSRC=	${WRKSRC}/qt5
INSTALL_WRKSRC=	${WRKSRC}/qt5
.else
CONFIGURE_ARGS+=--disable-poppler-qt5
.endif

.if ${SLAVEPORT}==utils
LIB_DEPENDS+=	libpoppler-glib.so:graphics/poppler-glib
CONFIGURE_ARGS+=--enable-utils
BUILD_WRKSRC=	${WRKSRC}/utils
INSTALL_WRKSRC=	${WRKSRC}/utils
.else
CONFIGURE_ARGS+=--disable-utils
.endif

.else # ! SLAVE options below
CONFIGURE_ARGS+=--disable-poppler-glib \
		--disable-poppler-qt4 \
		--disable-poppler-qt5 \
		--disable-utils

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=	libcairo.so:graphics/cairo
PLIST_SUB+=	CAIRO=""
.else
CONFIGURE_ARGS+=--disable-cairo-output
PLIST_SUB+=	CAIRO="@comment "
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	libcurl.so:ftp/curl
CONFIGURE_ARGS+=--enable-libcurl
PLIST_SUB+=	CURL=""
.else
CONFIGURE_ARGS+=--disable-libcurl
PLIST_SUB+=	CURL="@comment "
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
CONFIGURE_ARGS+=--enable-libopenjpeg=openjpeg2
LIB_DEPENDS+=	libopenjp2.so:graphics/openjpeg
.else
CONFIGURE_ARGS+=--enable-libopenjpeg=none
.endif
.endif # end of options

post-patch:
	@${REINPLACE_CMD} -e 's|-fno-check-new||g' ${WRKSRC}/configure

post-install:
.if defined(SLAVEPORT)
. if ${SLAVEPORT}==glib
	${INSTALL_DATA} ${WRKSRC}/poppler-glib.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig
. elif ${SLAVEPORT}==qt4
	${INSTALL_DATA} ${WRKSRC}/poppler-qt4.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig
. elif ${SLAVEPORT}==qt5
	${INSTALL_DATA} ${WRKSRC}/poppler-qt5.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig
. endif
.endif

.include <bsd.port.mk>
