# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	jfsw
PORTVERSION=	20051009
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://users.on.net/~jonof/buildport/
DISTFILES=	${PORTNAME}_src_${PORTVERSION}.zip \
		jfbuild_src_${PORTVERSION}.zip

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Jonathon Fowler's Shadow Warrior Port

LICENSE=	GPLv2 BuildLic
LICENSE_COMB=	multi
LICENSE_NAME_BuildLic=	Build source code license
LICENSE_FILE_BuildLic=	${WRKDIR}/jfbuild_src_${PORTVERSION}/buildlic.txt
LICENSE_PERMS_BuildLic=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

NO_CDROM=	Must be distributed only through the Internet and free of charge

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	uses x86 assembly code

USE_GL=		gl
USE_GNOME=	gtk20
USE_SDL=	mixer sdl
USE_GCC=	any

USES=	dos2unix gmake zip
DOS2UNIX_REGEX=	.*(\.(c|h)|Makefile)(\.deps)?

NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKDIR}/${PORTNAME}_src_${PORTVERSION}

SUB_FILES=	pkg-message

PORTDOCS=	readme.txt releasenotes.html

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|^(EROOT=)../build/|\1../jfbuild_src_${PORTVERSION}/|; \
		 s|^(CC=).*|\1${CC}|; \
		 s|^(CFLAGS=).*|\1${CFLAGS}|; \
		 s|^(NASMFLAGS=).*|\1 -s -f elf|; \
		 s|/usr/X11R6|${LOCALBASE}|; \
		 s|sdl-config|${SDL_CONFIG}|' \
		${BUILD_WRKSRC}/Makefile \
		${WRKDIR}/jfbuild_src_${PORTVERSION}/Makefile \
		${WRKDIR}/jfbuild_src_${PORTVERSION}/Makefile.shared
	@${REINPLACE_CMD} -e 's|/usr/share/games/jfsw|${DATADIR}|' \
		${BUILD_WRKSRC}/source/game.c \
		${BUILD_WRKSRC}/source/jnstub.c

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/sw ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/build ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-build
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${BUILD_WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
