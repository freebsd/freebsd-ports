# Created by: marcus@FreeBSD.org
# $FreeBSD$
#   $MCom: ports/graphics/poppler/Makefile,v 1.84 2013/03/12 14:53:49 kwm Exp $

PORTNAME=	poppler
PORTVERSION=	0.22.2
PORTREVISION?=	0
CATEGORIES=	graphics print
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A PDF rendering library

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		lcms2:${PORTSDIR}/graphics/lcms2
RUN_DEPENDS=	poppler-data>0:${PORTSDIR}/graphics/poppler-data

USES=		gmake pkgconfig
USE_GNOME=	gnomehack libxml2 ltverhack
USE_AUTOTOOLS=	libtool
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-zlib \
		--enable-xpdf-headers \
		--disable-gtk-test \
		--with-html-dir=${DOCSDIR}
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if !defined(SLAVEPORT)
PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	CAIRO OPENJPEG
OPTIONS_DEFAULT=CAIRO OPENJPEG
.endif

.include <bsd.port.options.mk>

.if defined(SLAVEPORT)
PORTSCOUT=	ignore:1
LIB_DEPENDS+=	poppler:${PORTSDIR}/graphics/poppler

.if ${SLAVEPORT}=="glib"
BUILD_DEPENDS+=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS+=	cairo:${PORTSDIR}/graphics/cairo
CONFIGURE_ARGS+=--enable-poppler-glib
USE_GNOME+=	gnomehier glib20
BUILD_WRKSRC=	${WRKSRC}/glib
INSTALL_WRKSRC=	${WRKSRC}/glib
.else
CONFIGURE_ARGS+=--disable-poppler-glib
.endif

.if ${SLAVEPORT}=="qt4"
CONFIGURE_ARGS+=--enable-poppler-qt4
CONFIGURE_ENV+=	ac_cv_prog_MOCQT4=${LOCALBASE}/bin/moc-qt4
USE_QT4=	gui corelib xml qtestlib moc_build
BUILD_WRKSRC=	${WRKSRC}/qt4
INSTALL_WRKSRC=	${WRKSRC}/qt4
.else
CONFIGURE_ARGS+=--disable-poppler-qt4
.endif

.if ${SLAVEPORT}=="utils"
LIB_DEPENDS+=	poppler-glib:${PORTSDIR}/graphics/poppler-glib
CONFIGURE_ARGS+=--enable-utils
BUILD_WRKSRC=	${WRKSRC}/utils
INSTALL_WRKSRC=	${WRKSRC}/utils
MAN1=		pdfdetach.1 pdffonts.1 pdfimages.1 pdfinfo.1 pdfseparate.1 \
		pdftocairo.1 pdftohtml.1  pdftops.1 pdftotext.1 pdftoppm.1 \
		pdfunite.1
.else
CONFIGURE_ARGS+=--disable-utils
.endif

.else
CONFIGURE_ARGS+=--disable-poppler-glib \
		--disable-poppler-qt4 \
		--disable-utils

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=	cairo:${PORTSDIR}/graphics/cairo
PLIST_SUB+=	CAIRO=""
.else
CONFIGURE_ARGS+=--disable-cairo-output
PLIST_SUB+=	CAIRO="@comment "
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
CONFIGURE_ARGS+=--enable-libopenjpeg
LIB_DEPENDS+=	openjpeg:${PORTSDIR}/graphics/openjpeg
.else
CONFIGURE_ARGS+=--disable-libopenjpeg
.endif
.endif

post-patch:
.if ${CXX:M*clang*} && ${CXXFLAGS:M-stdlib=libc++}
	@${REINPLACE_CMD} '/CXXFLAGS.*-ansi/d' ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|-version-info 35:0:0|-version-info 34:0:0|g' \
		${WRKSRC}/poppler/Makefile.in
.if defined(SLAVEPORT) && ${SLAVEPORT}=="qt4"
	@${REINPLACE_CMD} -e 's|MOCQT4=`.*|MOCQT4="${LOCALBASE}/bin/moc-qt4"|' \
		${WRKSRC}/configure
.endif

post-install:
.if defined(SLAVEPORT)
.if ${SLAVEPORT}=="glib"
	${INSTALL_DATA} ${WRKSRC}/poppler-glib.pc ${PREFIX}/libdata/pkgconfig
.elif ${SLAVEPORT}=="qt4"
	${INSTALL_DATA} ${WRKSRC}/poppler-qt4.pc ${PREFIX}/libdata/pkgconfig
.endif
.endif

.include <bsd.port.mk>
