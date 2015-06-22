# Created by: marcus@FreeBSD.org
# $FreeBSD$
#   $MCom: ports/graphics/poppler/Makefile,v 1.84 2013/03/12 14:53:49 kwm Exp $

PORTNAME=	poppler
PORTVERSION=	0.30.0
PORTREVISION?=	0
CATEGORIES=	graphics print
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	PDF rendering library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libfreetype.so:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	poppler-data>0:${PORTSDIR}/graphics/poppler-data

USES=		cpe gmake jpeg libtool pathfix pkgconfig tar:xz
CPE_VENDOR=	freedesktop
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-zlib \
		--enable-xpdf-headers \
		--disable-gtk-test \
		--without-html-dir \
		--disable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# see https://bugs.freedesktop.org/show_bug.cgi?id=72499
CPPFLAGS+=	 -D__LONG_LONG_SUPPORTED

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
LIB_DEPENDS+=	libpoppler.so:${PORTSDIR}/graphics/poppler

.if ${SLAVEPORT}==glib
CONFIGURE_ARGS+=--enable-poppler-glib --enable-introspection=yes
USE_GNOME+=	cairo glib20 introspection:build
BUILD_WRKSRC=	${WRKSRC}/glib
INSTALL_WRKSRC=	${WRKSRC}/glib
.else
CONFIGURE_ARGS+=--disable-poppler-glib
.endif

.if ${SLAVEPORT}==qt4
CONFIGURE_ARGS+=--enable-poppler-qt4
CONFIGURE_ENV+=	MOCQT4=${MOC}
USE_QT4=	gui corelib xml qtestlib moc_build
BUILD_WRKSRC=	${WRKSRC}/qt4
INSTALL_WRKSRC=	${WRKSRC}/qt4
.else
CONFIGURE_ARGS+=--disable-poppler-qt4
.endif

.if ${SLAVEPORT}==qt5
CONFIGURE_ARGS+=--enable-poppler-qt5
CONFIGURE_ENV+=	MOCQT5=${MOC}
USE_QT5=	core gui widgets xml buildtools_build testlib_build
BUILD_WRKSRC=	${WRKSRC}/qt5
INSTALL_WRKSRC=	${WRKSRC}/qt5
.else
CONFIGURE_ARGS+=--disable-poppler-qt5
.endif

.if ${SLAVEPORT}==utils
LIB_DEPENDS+=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib
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
LIB_DEPENDS+=	libcairo.so:${PORTSDIR}/graphics/cairo
PLIST_SUB+=	CAIRO=""
.else
CONFIGURE_ARGS+=--disable-cairo-output
PLIST_SUB+=	CAIRO="@comment "
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--enable-libcurl
PLIST_SUB+=	CURL=""
.else
CONFIGURE_ARGS+=--disable-libcurl
PLIST_SUB+=	CURL="@comment "
.endif

# stick with openjpeg1 for now due to regression in openjpeg2 (configure)
# https://bugs.freedesktop.org/show_bug.cgi?id=58906 Comment #35
.if ${PORT_OPTIONS:MOPENJPEG}
CONFIGURE_ARGS+=--enable-libopenjpeg=openjpeg1
LIB_DEPENDS+=	libopenjpeg.so:${PORTSDIR}/graphics/openjpeg15
.else
CONFIGURE_ARGS+=--disable-libopenjpeg
.endif
.endif # end of options

post-patch:
	@${REINPLACE_CMD} '/CXXFLAGS.*-ansi/d' ${WRKSRC}/configure
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
