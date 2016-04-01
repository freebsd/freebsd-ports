# Created by: Alexander Best <arundel@gmx.net>
# $FreeBSD$

PORTNAME=	vba
PORTVERSION=	1.7.2
PORTREVISION=	13
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/VisualBoyAdvance/${PORTVERSION}
DISTNAME=	VisualBoyAdvance-src-${PORTVERSION}

MAINTAINER=	arundel@h3c.de
COMMENT=	Open source Gameboy Advance emulator

LICENSE=	GPLv2

BUILD_DEPENDS=	nasm:devel/nasm
LIB_DEPENDS=	libpng.so:graphics/png

USES=		gettext gmake
GNU_CONFIGURE=	yes
USE_SDL=	sdl

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lintl

WRKSRC=		${WRKDIR}/VisualBoyAdvance-${PORTVERSION}
SUB_FILES=	pkg-message

DATA_FILES=	${WRKSRC}/src/VisualBoyAdvance.cfg
PROG_FILES=	${WRKSRC}/src/sdl/VisualBoyAdvance
PORTDOCS=	AUTHORS NEWS README ChangeLog

OPTIONS_DEFINE=	DOCS GTK2 PROFILING
OPTIONS_SUB=	yes
PROFILING_DESC=	Enable profiling

GTK2_CONFIGURE_ON=	--enable-gtk=2.4
GTK2_LIB_DEPENDS=	libglademm-2.4.so:devel/libglademm24
GTK2_USES=		pkgconfig
PROFILING_CONFIGURE_ENABLE=	profiling

BROKEN_ia64=	Runaway cc1plus process
BROKEN_powerpc=	Runaway cc1plus process
BROKEN_sparc64=	Runaway cc1plus process

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
PROG_FILES+=		${WRKSRC}/src/gtk/gvba
GTK2_DATA_FILES=	${WRKSRC}/src/gtk/vba.glade
.endif

post-patch:
	@${REINPLACE_CMD} -e '/for(int i = 0; i < 16; i++/s| i|&_|g' \
		${WRKSRC}/src/sdl/debugger.cpp
	@${REINPLACE_CMD} -e '/^namespace std/ { x; \
		s|^|#include <sys/types.h>|; H; x; }' ${WRKSRC}/src/expr.cpp

do-install:
	${INSTALL_PROGRAM} ${PROG_FILES} ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MGTK2}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/VisualBoyAdvance
	${INSTALL_DATA} ${GTK2_DATA_FILES} ${STAGEDIR}${PREFIX}/share/VisualBoyAdvance
.endif
	${SED} -e 's|filter=0|filter=1|' ${DATA_FILES} > ${DATA_FILES}-default
	${INSTALL_DATA} ${DATA_FILES}-default ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
