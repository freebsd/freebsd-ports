PORTNAME=	vba
PORTVERSION=	1.7.2
PORTREVISION=	13
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/VisualBoyAdvance/${PORTVERSION}
DISTNAME=	VisualBoyAdvance-src-${PORTVERSION}

MAINTAINER=	arundel@h3c.de
COMMENT=	Open source Gameboy Advance emulator
WWW=		https://web.archive.org/web/20110718045837/http://vba.ngemu.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc=		Runaway cc1plus process

BUILD_DEPENDS=	nasm:devel/nasm
LIB_DEPENDS=	libpng.so:graphics/png

USES=		gettext gmake localbase sdl
USE_CXXSTD=	c++14
USE_SDL=	sdl

GNU_CONFIGURE=	yes

LIBS+=		-lintl

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/VisualBoyAdvance-${PORTVERSION}

PORTDOCS=	AUTHORS NEWS README ChangeLog

OPTIONS_DEFINE=	DOCS GTK2 PROFILING
OPTIONS_SUB=	yes
PROFILING_DESC=	Enable profiling

GTK2_LIB_DEPENDS=	libglademm-2.4.so:devel/libglademm24
GTK2_USES=		pkgconfig
GTK2_CONFIGURE_ON=	--enable-gtk=2.4
GTK2_VARS=	PROG_FILES+=${WRKSRC}/src/gtk/gvba \
		GTK2_DATA_FILES=${WRKSRC}/src/gtk/vba.glade
PROFILING_CONFIGURE_ENABLE=	profiling

DATA_FILES=	${WRKSRC}/src/VisualBoyAdvance.cfg
PROG_FILES=	${WRKSRC}/src/sdl/VisualBoyAdvance

post-patch:
	@${REINPLACE_CMD} -e '/for(int i = 0; i < 16; i++/s| i|&_|g' \
		${WRKSRC}/src/sdl/debugger.cpp

do-install:
	${INSTALL_PROGRAM} ${PROG_FILES} ${STAGEDIR}${PREFIX}/bin
	${SED} -e 's|filter=0|filter=1|' ${DATA_FILES} > ${DATA_FILES}-default
	${INSTALL_DATA} ${DATA_FILES}-default ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-install-GTK2-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/VisualBoyAdvance
	${INSTALL_DATA} ${GTK2_DATA_FILES} ${STAGEDIR}${PREFIX}/share/VisualBoyAdvance

.include <bsd.port.mk>
