# New ports collection makefile for:	eduke32
# Date Created:				1 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$

PORTNAME=	eduke32
PORTVERSION=	20060718
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}_src_${PORTVERSION}${EXTRACT_SUFX} \
		txbuild_src_${PORTVERSION}${EXTRACT_SUFX}

PATCH_SITES=	http://mephisto.ma.cx/mephisto/patches/
PATCHFILES=	${PORTNAME}_src_${PORTVERSION}.patch \
		txbuild_src_${PORTVERSION}.patch
PATCH_DIST_STRIP=	-p0

MAINTAINER=	olivier@gid0.org
COMMENT=	Duke Nukem 3D Port based on JFDuke and EDuke

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

BROKEN=		Unfetchable

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	uses i386 assembly code
REINPLACE_ARGS=	-i ''
USE_ZIP=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_GNOME=	gtk20
USE_SDL=	mixer sdl
WRKSRC=		${WRKDIR}/${PORTNAME}_src_${PORTVERSION}
PATCH_WRKSRC=	${WRKDIR}

OPTIONS=	MIDI "Enable MIDI support" on

.include "${.CURDIR}/../duke3d-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MIDI)
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|^(EROOT=)../build/|\1../txbuild_src_${PORTVERSION}/|; \
		 s|^(CC=).*|\1${CC}|; \
		 s|^(CXX=).*|\1${CXX}|; \
		 s|^(NASMFLAGS=).*|\1 -s -f elf|; \
		 s|/usr/X11R6|${X11BASE}|; \
		 s|sdl-config|${SDL_CONFIG}|' \
		${WRKSRC}/Makefile \
		${WRKDIR}/txbuild_src_${PORTVERSION}/Makefile \
		${WRKDIR}/txbuild_src_${PORTVERSION}/Makefile.shared
	@${REINPLACE_CMD} -e 's|/usr/share/games/eduke32|${DN3DDIR}|' \
		${WRKSRC}/source/game.c ${WRKSRC}/source/astub.c
	@${REINPLACE_CMD} -e 's,^#if defined RENDERTYPEWIN || .*,#if 0,' \
		${WRKSRC}/source/game.c

do-install:
.for f in eduke32 mapster32
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
. for f in ChangeLog *.sample
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
