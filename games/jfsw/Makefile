# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	jfsw
PORTVERSION=	20051009
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://users.on.net/~jonof/buildport/
DISTFILES=	${PORTNAME}_src_${PORTVERSION}.zip \
		jfbuild_src_${PORTVERSION}.zip

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Jonathon Fowler's Shadow Warrior Port

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	uses x86 assembly code
USE_ZIP=	yes
USE_GMAKE=	yes
USE_GL=		gl
USE_GNOME=	gtk20
USE_SDL=	mixer sdl
WRKSRC=		${WRKDIR}/${PORTNAME}_src_${PORTVERSION}
PATCH_WRKSRC=	${WRKDIR}

SUB_FILES=	pkg-message

PORTDOCS=	readme.txt releasenotes.html

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|^(EROOT=)../build/|\1../jfbuild_src_${PORTVERSION}/|; \
		 s|^(CC=).*|\1${CC}|; \
		 s|^(CFLAGS=).*|\1${CFLAGS}|; \
		 s|^(NASMFLAGS=).*|\1 -s -f elf|; \
		 s|/usr/X11R6|${LOCALBASE}|; \
		 s|sdl-config|${SDL_CONFIG}|' \
		${WRKSRC}/Makefile \
		${WRKDIR}/jfbuild_src_${PORTVERSION}/Makefile \
		${WRKDIR}/jfbuild_src_${PORTVERSION}/Makefile.shared
	@${REINPLACE_CMD} -e 's|/usr/share/games/jfsw|${DATADIR}|' \
		${WRKSRC}/source/game.c ${WRKSRC}/source/jnstub.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sw ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/build ${PREFIX}/bin/${PORTNAME}-build
	${MKDIR} ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
