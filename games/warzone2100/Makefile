# $FreeBSD$

PORTNAME=	warzone2100
PORTVERSION=	3.2.1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}/

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
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USES=		bison compiler:c++11-lib gmake localbase openal:al pkgconfig ssl tar:xz
GNU_CONFIGURE=	yes
USE_GL=		gl glu glew
USE_SDL=	sdl2
USE_XORG=	x11 xrandr
USE_QT5=	core gui widgets script buildtools_build
QT_NONSTANDARD=	yes
CONFIGURE_ARGS=	--program-transform-name="" --with-distributor="FreeBSD ports"
CONFIGURE_ENV=	LIBCRYPTO_CFLAGS="-I${OPENSSLINC}" \
		LIBCRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto"

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
	@${REINPLACE_CMD} -e '/INSTALL_DATA.*warzone2100.appdata.xml/d' ${WRKSRC}/icons/Makefile.*

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/appdata

.include <bsd.port.mk>
