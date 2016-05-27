# $FreeBSD$

PORTNAME=	warzone2100
PORTVERSION=	3.1.5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Innovative 3D real-time strategy game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip \
		unzip:archivers/unzip
LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libtheora.so:multimedia/libtheora \
		libfribidi.so:converters/fribidi \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USES=		bison compiler:c++11-lang gmake localbase openal:al pkgconfig tar:xz # actually, old gcc fails on unknown -W flag
GNU_CONFIGURE=	yes
USE_GL=		glew glu
USE_SDL=	sdl
USE_QT4=	corelib network script gui moc_build
QT_NONSTANDARD=	yes
CONFIGURE_ARGS=	--program-transform-name="" --with-distributor="FreeBSD ports"
CONFIGURE_ENV=	PATH="${LOCALBASE}/bin:$$PATH" \
		CCOMPILER="${CC}" \
		CXXCOMPILER="${CXX}"
REINPLACE_ARGS=	-i ''

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

MANPAGES_BUILD_DEPENDS=	a2x:textproc/asciidoc

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g; s|-R$$found_dir||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|./build_tools/autorevision|& -f|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
