# $FreeBSD$

PORTNAME=	warzone2100
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Innovative 3D real-time strategy game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	physfs:${PORTSDIR}/devel/physfs \
		png15:${PORTSDIR}/graphics/png \
		vorbis:${PORTSDIR}/audio/libvorbis \
		theora:${PORTSDIR}/multimedia/libtheora \
		GLEW:${PORTSDIR}/graphics/glew \
		fribidi:${PORTSDIR}/converters/fribidi \
		freetype:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf:${PORTSDIR}/x11-fonts/dejavu

USE_XZ=		yes
USES=		bison gmake pkgconfig
GNU_CONFIGURE=	yes
USE_OPENAL=	al
USE_GL=		yes
USE_SDL=	sdl
USE_QT4=	corelib network script gui moc_build
QT_NONSTANDARD=	yes
CONFIGURE_ARGS=	--program-transform-name="" --with-distributor="FreeBSD ports"
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}" \
		PATH="${LOCALBASE}/bin:$$PATH"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
REINPLACE_ARGS=	-i ''
PORTDOCS=	*
USE_GCC=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -Ee 's|install-dist_docDATA$$||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^install: install-am|install:|' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
