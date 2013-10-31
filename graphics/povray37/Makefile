# $FreeBSD$

PORTNAME=	povray
DISTVERSION=	3.7.0.RC6
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.povray.org/beta/source/
DIST_SUBDIR=	${UNIQUENAME}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Persistence of Vision Ray Tracer

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	X11 PNG JPEG TIFF OPENEXR STATIC IO EXAMPLES DOCS
OPTIONS_DEFAULT=	PNG JPEG EXAMPLES DOCS
IO_DESC=	Without I/O restrictions (security risk)
EXAMPLES_DESC=	Install example scenes
DOCS_DESC=	Install HTML documentation

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
LATEST_LINK=	${PORTNAME}37

VERSION_BASE=	${PORTVERSION:C/([0-9]+\.[0-9]+).*/\1/}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${VERSION_BASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${VERSION_BASE}
DATADIR=	${PREFIX}/share/${PORTNAME}-${VERSION_BASE}
ETCDIR=		${PREFIX}/etc/${PORTNAME}/${VERSION_BASE}

INCLUDES=	-I${LOCALBASE}/include

CONFIGURE_ARGS=	COMPILED_BY=${MAINTAINER} --prefix=${PREFIX} \
		--program-transform-name='s/${PORTNAME}/${UNIQUENAME}/' \
		--disable-optimiz

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=		xpm sm ice x11
USE_SDL=		sdl
CONFIGURE_ARGS+=	--x-include=${LOCALBASE}/include --x-libraries=${LOCALBASE}/libs
PLIST_SUB+=		X11=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
.endif

.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=--enable-static
.endif

.if ${PORT_OPTIONS:MIO}
CONFIGURE_ARGS+=--disable-io-restrictions
.endif

.if ${PORT_OPTIONS:MPNG}
.if ${PORT_OPTIONS:MSTATIC}
BUILD_DEPENDS+=	png>=1.4:${PORTSDIR}/graphics/png
.else
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
LIBS+=		-lpng
.endif
.else
CONFIGURE_ARGS+=--without-libpng
.endif

.if ${PORT_OPTIONS:MJPEG}
.if ${PORT_OPTIONS:MSTATIC}
BUILD_DEPENDS+=	jpeg>=6b:${PORTSDIR}/graphics/jpeg
.else
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
LIBS+=		-ljpeg
.endif
.else
CONFIGURE_ARGS+=--without-libjpeg
.endif

.if ${PORT_OPTIONS:MTIFF}
.if ${PORT_OPTIONS:MSTATIC}
BUILD_DEPENDS+=	tiff>=4:${PORTSDIR}/graphics/tiff
.else
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
LIBS+=		-ltiff
.endif
.else
CONFIGURE_ARGS+=--without-libtiff
.endif

.if ${PORT_OPTIONS:MOPENEXR}
.if ${PORT_OPTIONS:MSTATIC}
BUILD_DEPENDS+=	OpenEXR>=1.6:${PORTSDIR}/graphics/OpenEXR
.else
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
LIBS+=		-lIlmImf
INCLUDES+=	-I${LOCALBASE}/include/OpenEXR
.endif
.else
CONFIGURE_ARGS+=--without-openexr
.endif

.if !${PORT_OPTIONS:MPNG} || !${PORT_OPTIONS:MJPEG} || !${PORT_OPTIONS:MTIFF}
CONFIGURE_ARGS+=NON_REDISTRIBUTABLE_BUILD=yes
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: thread-local storage not supported
.endif

CONFIGURE_ARGS+=CXXFLAGS="${CXXFLAGS} ${INCLUDES}"

MAN1=		${UNIQUENAME}.1

DOC_FILES=	AUTHORS ChangeLog NEWS
PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
# Fix with boost 1.52
	@${REINPLACE_CMD} -e 's/TIME_UTC/TIME_UTC_/g' ${WRKSRC}/source/backend/scene/view.cpp \
		${WRKSRC}/source/base/timer.cpp \
		${WRKSRC}/vfe/vfepovms.cpp \
		${WRKSRC}/vfe/unix/platformbase.cpp \
		${WRKSRC}/vfe/vfesession.cpp
pre-build:
.if ${PORT_OPTIONS:MSTATIC} && ${PORT_OPTIONS:MTIFF}
#	graphics/tiff adds dependencies on libjpeg and libjbig
	@${REINPLACE_CMD} -e 's,^\(LIBS = .*\)-ltiff\(.*\),\1-ltiff -ljpeg -ljbig\2,' ${WRKSRC}/unix/Makefile
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/unix/${PORTNAME} ${PREFIX}/bin/${UNIQUENAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/${MAN1}
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini ${ETCDIR}
.for i in include ini scripts
	${MKDIR} ${DATADIR}/$i
	cd ${WRKSRC}/$i && ${COPYTREE_SHARE} . ${DATADIR}/$i
.endfor
.if ${PORT_OPTIONS:MX11}
	@${MKDIR} ${DATADIR}/icons
	cd ${WRKSRC}/icons && ${COPYTREE_SHARE} . ${DATADIR}/icons
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/scenes && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOC_FILES} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
