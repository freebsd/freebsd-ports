# New ports collection makefile for:    POV-Ray
# Date created:         3 Dec 1996
# Whom:                 paulo@isr.uc.pt
#
# $FreeBSD$
#

PORTNAME=	povray
DISTVERSION=	3.7.0.RC3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.povray.org/beta/source/
DIST_SUBDIR=	${UNIQUENAME}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Persistence of Vision Ray Tracer

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

OPTIONS=	X11 "X Window display support" OFF \
		PNG "PNG support" ON \
		JPEG "JPEG support" ON \
		TIFF "TIFF support" OFF \
		OPENEXR "OpenEXR support" OFF \
		STATIC "Build static binary" OFF \
		IO "Disable I/O restrictions (security risk)" OFF \
		EXAMPLES "Install example scenes" ON \
		HTML "Install HTML documentation" ON

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
LATEST_LINK=	${PORTNAME}37

VERSION_BASE=	${PORTVERSION:C/([0-9]+\.[0-9]+).*/\1/}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${VERSION_BASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${VERSION_BASE}
DATADIR=	${PREFIX}/share/${PORTNAME}-${VERSION_BASE}
ETCDIR=		${PREFIX}/etc/${PORTNAME}/${VERSION_BASE}

.include <bsd.port.pre.mk>

INCLUDES=	-I${LOCALBASE}/include

CONFIGURE_ARGS=	COMPILED_BY=${MAINTAINER} --prefix=${PREFIX} \
		--program-transform-name='s/${PORTNAME}/${UNIQUENAME}/' \
		--disable-optimiz

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
.else
USE_XORG=		xpm sm ice x11
USE_SDL=		sdl
CONFIGURE_ARGS+=	--x-include=${LOCALBASE}/include --x-libraries=${LOCALBASE}/libs
PLIST_SUB+=		X11=""
.endif

.if defined(WITH_STATIC)
CONFIGURE_ARGS+=--enable-static
.endif

.if defined(WITH_IO)
CONFIGURE_ARGS+=--disable-io-restrictions
.endif

.if defined(WITH_PNG)
.if defined(WITH_STATIC)
BUILD_DEPENDS+=	png>=1.4:${PORTSDIR}/graphics/png
.else
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
LIBS+=		-lpng
.endif
.else
CONFIGURE_ARGS+=--without-libpng
.endif

.if defined(WITH_JPEG)
.if defined(WITH_STATIC)
BUILD_DEPENDS+=	jpeg>=6b:${PORTSDIR}/graphics/jpeg
.else
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
LIBS+=		-ljpeg
.endif
.else
CONFIGURE_ARGS+=--without-libjpeg
.endif

.if defined(WITH_TIFF)
.if defined(WITH_STATIC)
BUILD_DEPENDS+=	tiff>=4:${PORTSDIR}/graphics/tiff
.else
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
LIBS+=		-ltiff
.endif
.else
CONFIGURE_ARGS+=--without-libtiff
.endif

.if defined(WITH_OPENEXR)
.if defined(WITH_STATIC)
BUILD_DEPENDS+=	OpenEXR>=1.6:${PORTSDIR}/graphics/OpenEXR
.else
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
LIBS+=		-lIlmImf
INCLUDES+=	-I${LOCALBASE}/include/OpenEXR
.endif
.else
CONFIGURE_ARGS+=--without-openexr
.endif

.if defined(WITHOUT_PNG) || defined(WITHOUT_JPEG) || defined(WITHOUT_TIFF)
CONFIGURE_ARGS+=NON_REDISTRIBUTABLE_BUILD=yes
.endif

.if defined(WITHOUT_EXAMPLES)
PLIST_SUB+=	EXAMPLES="@comment "
.else
PLIST_SUB+=	EXAMPLES=""
.endif

.if defined(WITHOUT_HTML)
PLIST_SUB+=	HTML="@comment "
.else
PLIST_SUB+=	HTML=""
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: thread-local storage not supported
.endif

CONFIGURE_ARGS+=CXXFLAGS="${CXXFLAGS} ${INCLUDES}"

MAN1=		${UNIQUENAME}.1

DOC_FILES=	AUTHORS ChangeLog NEWS

pre-build:
.if defined(WITH_STATIC) && defined(WITH_TIFF)
#	graphics/tiff adds dependencies on libjpeg and libjbig
	@${REINPLACE_CMD} -e 's,^\(LIBS = .*\)-ltiff\(.*\),\1-ltiff -ljpeg -ljbig\2,' ${WRKSRC}/unix/Makefile
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/unix/${PORTNAME} ${PREFIX}/bin/${UNIQUENAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/${MAN1}
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini ${ETCDIR}
	@${MKDIR} ${DATADIR}/include ${DATADIR}/ini ${DATADIR}/scripts
	@filelist=`find ${WRKSRC}/include/ ${WRKSRC}/ini/ ${WRKSRC}/scripts/ -type f | ${SED} s,${WRKSRC}/,,`; \
	for f in $$filelist ; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DATADIR}//$$f; \
	done
.if !defined(WITHOUT_X11)
	@${MKDIR} ${DATADIR}/icons
	@filelist=`find ${WRKSRC}/icons/ -type f | ${SED} s,${WRKSRC}/icons/,,`; \
	for f in $$filelist ; do \
		${INSTALL_DATA} ${WRKSRC}/icons/$$f ${DATADIR}/icons/$$f; \
	done
.endif
.if !defined(WITHOUT_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@dirlist=`find ${WRKSRC}/scenes/ -type d | ${SED} s,${WRKSRC}/scenes/,,`; \
	for p in "" $$dirlist ; do \
		${MKDIR} ${EXAMPLESDIR}/$$p; \
	done
	@filelist=`find ${WRKSRC}/scenes/ -type f | ${SED} s,${WRKSRC}/scenes/,,`; \
	for f in $$filelist ; do \
		${INSTALL_DATA} ${WRKSRC}/scenes/$$f ${EXAMPLESDIR}/$$f; \
	done
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for f in ${DOC_FILES} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}/$$f; \
	done
.if !defined(WITHOUT_HTML)
	@dirlist=`find ${WRKSRC}/doc/ -type d | ${SED} s,${WRKSRC}/doc/,,`; \
	for p in "" $$dirlist ; do \
		${MKDIR} ${DOCSDIR}/$$p; \
	done
	@filelist=`find ${WRKSRC}/doc/ -type f | ${SED} s,${WRKSRC}/doc/,,`; \
	for f in $$filelist ; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$f ${DOCSDIR}/$$f; \
	done
.endif
.endif

.include <bsd.port.post.mk>
