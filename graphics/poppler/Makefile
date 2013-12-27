# Created by: marcus@FreeBSD.org
# $FreeBSD$
#   $MCom: ports/graphics/poppler/Makefile,v 1.84 2013/03/12 14:53:49 kwm Exp $

PORTNAME=	poppler
PORTVERSION=	0.24.4
PORTREVISION?=	0
CATEGORIES=	graphics print
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	PDF rendering library

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		liblcms2.so:${PORTSDIR}/graphics/lcms2
RUN_DEPENDS=	poppler-data>0:${PORTSDIR}/graphics/poppler-data

USE_XZ=		yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	libxml2 ltverhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-zlib \
		--enable-xpdf-headers \
		--disable-gtk-test \
		--with-html-dir=${DOCSDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# see https://bugs.freedesktop.org/show_bug.cgi?id=72499
CPPFLAGS+=	 -D__LONG_LONG_SUPPORTED

.if !defined(SLAVEPORT)
PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	CAIRO OPENJPEG
OPTIONS_DEFAULT=CAIRO OPENJPEG
.endif

.include <bsd.port.options.mk>

.if defined(SLAVEPORT)
PORTSCOUT=	ignore:1
LIB_DEPENDS+=	libpoppler.so:${PORTSDIR}/graphics/poppler

.if ${SLAVEPORT}==glib
CONFIGURE_ARGS+=--enable-poppler-glib
USE_GNOME+=	cairo gnomehier glib20 introspection:build
BUILD_WRKSRC=	${WRKSRC}/glib
INSTALL_WRKSRC=	${WRKSRC}/glib
.else
CONFIGURE_ARGS+=--disable-poppler-glib
.endif

.if ${SLAVEPORT}==qt4
CONFIGURE_ARGS+=--enable-poppler-qt4
CONFIGURE_ENV+=	ac_cv_prog_MOCQT4=${LOCALBASE}/bin/moc-qt4
USE_QT4=	gui corelib xml qtestlib moc_build
BUILD_WRKSRC=	${WRKSRC}/qt4
INSTALL_WRKSRC=	${WRKSRC}/qt4
.else
CONFIGURE_ARGS+=--disable-poppler-qt4
.endif

# needs checking when Qt5 is available
.if ${SLAVEPORT}==qt5
CONFIGURE_ARGS+=--enable-poppler-qt5
CONFIGURE_ENV+=	ac_cv_prog_MOCQT4=${LOCALBASE}/bin/moc-qt5
USE_QT5=	gui corelib xml qtestlib moc_build
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

.else
CONFIGURE_ARGS+=--disable-poppler-glib \
		--disable-poppler-qt4 \
		--disable-utils

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=	libcairo.so:${PORTSDIR}/graphics/cairo
PLIST_SUB+=	CAIRO=""
.else
CONFIGURE_ARGS+=--disable-cairo-output
PLIST_SUB+=	CAIRO="@comment "
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
CONFIGURE_ARGS+=--enable-libopenjpeg
LIB_DEPENDS+=	libopenjpeg.so:${PORTSDIR}/graphics/openjpeg
.else
CONFIGURE_ARGS+=--disable-libopenjpeg
.endif
.endif

post-patch:
.if ${CXX:M*clang*} && ${CXXFLAGS:M-stdlib=libc++}
	@${REINPLACE_CMD} '/CXXFLAGS.*-ansi/d' ${WRKSRC}/configure
.endif
#	@${REINPLACE_CMD} -e 's|-version-info 35:0:0|-version-info 34:0:0|g' \
#		${WRKSRC}/poppler/Makefile.in
.if defined(SLAVEPORT) && ${SLAVEPORT}==qt4
	@${REINPLACE_CMD} -e 's|MOCQT4=`.*|MOCQT4="${LOCALBASE}/bin/moc-qt4"|' \
		${WRKSRC}/configure
.endif
.if defined(SLAVEPORT) && ${SLAVEPORT}==qt5
	@${REINPLACE_CMD} -e 's|MOCQT5=`.*|MOCQT5="${LOCALBASE}/bin/moc-qt5"|' \
		${WRKSRC}/configure
.endif

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
	-@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpoppler*.so.*

.include <bsd.port.mk>
