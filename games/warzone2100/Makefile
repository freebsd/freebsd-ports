# $FreeBSD$

PORTNAME=	warzone2100
PORTVERSION=	3.1.1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Innovative 3D real-time strategy game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	libphysfs.so:${PORTSDIR}/devel/physfs \
		libpng.so:${PORTSDIR}/graphics/png \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libtheora.so:${PORTSDIR}/multimedia/libtheora \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf:${PORTSDIR}/x11-fonts/dejavu

USE_XZ=		yes
USES=		bison gmake openal:al pkgconfig compiler:c++11-lang # actually, old gcc fails on unknown -W flag
GNU_CONFIGURE=	yes
USE_GL=		yes
USE_SDL=	sdl
USE_QT4=	corelib network script gui moc_build
QT_NONSTANDARD=	yes
CONFIGURE_ARGS=	--program-transform-name="" --with-distributor="FreeBSD ports"
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}" \
		PATH="${LOCALBASE}/bin:$$PATH" \
		CCOMPILER="${CC}" \
		CXXCOMPILER="${CXX}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
REINPLACE_ARGS=	-i ''

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

MANPAGES_BUILD_DEPENDS=	a2x:${PORTSDIR}/textproc/asciidoc

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g; s|-R$$found_dir||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|./build_tools/autorevision|& -f|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
