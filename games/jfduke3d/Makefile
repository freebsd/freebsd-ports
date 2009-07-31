# New ports collection makefile for:	jfduke3d
# Date Created:				26 August 2005
# Whom:					<arundel@h3c.de>
#
# $FreeBSD$

PORTNAME=	jfduke3d
PORTVERSION=	20051009
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://users.on.net/~jonof/buildport/
DISTFILES=	${PORTNAME}_src_${PORTVERSION}.zip \
		jfbuild_src_${PORTVERSION}.zip

PATCH_SITES=	http://www.mephisto.ma.cx/mephisto/patches/
PATCHFILES=	${PORTNAME}_src_${PORTVERSION}.patch \
		jfbuild_src_${PORTVERSION}.patch

MAINTAINER=	arundel@h3c.de
COMMENT=	Jonathon Fowler's Duke Nukem 3D Port

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
	@${REINPLACE_CMD} -e 's|/usr/share/games/jfduke3d|${DN3DDIR}|' \
		${WRKSRC}/source/game.c ${WRKSRC}/source/astub.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/duke3d ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/build ${PREFIX}/bin/${PORTNAME}-build
.if !defined(NOPORTDOCS)
.for f in ChangeLog readme.txt releasenotes.html duke3d.def.sample
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../duke3d-data/Makefile.include"

.include <bsd.port.mk>
