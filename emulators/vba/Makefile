# Created by: Alexander Best <arundel@gmx.net>
# $FreeBSD$

PORTNAME=	vba
PORTVERSION=	1.7.2
PORTREVISION=	10
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/VisualBoyAdvance/${PORTVERSION}
DISTNAME=	VisualBoyAdvance-src-${PORTVERSION}

MAINTAINER=	arundel@h3c.de
COMMENT=	Open source Gameboy Advance emulator

LICENSE=	GPLv2

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USES=		gettext gmake
GNU_CONFIGURE=	yes
USE_SDL=	sdl
CONFIGURE_ARGS=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}" LIBS="-lintl"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/VisualBoyAdvance-${PORTVERSION}
SUB_FILES=	pkg-message

DATA_FILES=	${WRKSRC}/src/VisualBoyAdvance.cfg
PROG_FILES=	${WRKSRC}/src/sdl/VisualBoyAdvance
PORTDOCS=	AUTHORS NEWS README ChangeLog

OPTIONS_DEFINE=	GTK2 PROFILING DOCS
OPTIONS_SUB=	yes
PROFILING_DESC=	Enable profiling

GTK2_CONFIGURE_ON=	--enable-gtk=2.4
PROFILING_CONFIGURE_ENABLE=	profiling

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGTK2}
LIB_DEPENDS+=	glademm-2.4:${PORTSDIR}/devel/libglademm24
PROG_FILES+=	${WRKSRC}/src/gtk/gvba
GTK2_DATA_FILES=	${WRKSRC}/src/gtk/vba.glade
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Runaway cc1plus process
.endif

post-patch:
	@${REINPLACE_CMD} -e '/for(int i = 0; i < 16; i++/s| i|&_|g' \
		${WRKSRC}/src/sdl/debugger.cpp
	@${REINPLACE_CMD} -e '/^namespace std/ { x; \
		s|^|#include <sys/types.h>|; H; x; }' ${WRKSRC}/src/expr.cpp

do-install:
	${INSTALL_PROGRAM} ${PROG_FILES} ${PREFIX}/bin
.if ${PORT_OPTIONS:MGTK2}
	@${MKDIR} ${PREFIX}/share/VisualBoyAdvance
	${INSTALL_DATA} ${GTK2_DATA_FILES} ${PREFIX}/share/VisualBoyAdvance
.endif
	${SED} -e 's|filter=0|filter=1|' ${DATA_FILES} > ${DATA_FILES}-default
	${INSTALL_DATA} ${DATA_FILES}-default ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
