# $FreeBSD$

PORTNAME=	warzone2100
PORTVERSION=	3.3.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Innovative 3D real-time strategy game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libfribidi.so:converters/fribidi \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USES=		autoreconf bison compiler:c++11-lib gl gmake localbase openal:al pkgconfig \
		qmake:no_env qt:5 sdl ssl tar:xz xorg
GNU_CONFIGURE=	yes
USE_GL=		gl glu glew
USE_SDL=	sdl2
USE_XORG=	x11 xrandr
USE_QT=		core gui widgets script buildtools_build
CONFIGURE_ARGS=	--program-transform-name="" --with-distributor="FreeBSD ports"
CONFIGURE_ENV=	LIBCRYPTO_CFLAGS="-I${OPENSSLINC}" \
		LIBCRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
		CCOMPILER="${CC}" CXXCOMPILER="${CXX}"

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

MANPAGES_BUILD_DEPENDS=	a2x:textproc/asciidoc

post-patch:
	@${REINPLACE_CMD} -e 's|./build_tools/autorevision|& -f|g' ${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
