# New ports collection makefile for:	eduke32
# Date Created:				1 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$

PORTNAME=	eduke32
PORTVERSION=	20060718
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}_src_${PORTVERSION}.zip \
		txbuild_src_${PORTVERSION}.zip

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Duke Nukem 3D Port based on JFDuke and EDuke

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_ZIP=	yes
USE_GCC=	3.2+
USE_GMAKE=	yes
USE_GL=		yes
USE_GNOME=	gtk20
USE_SDL=	mixer sdl
WRKSRC=		${WRKDIR}/${PORTNAME}_src_${PORTVERSION}

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

do-install:
.for f in eduke32 mapster32
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
.for f in ChangeLog *.sample
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../duke3d-data/Makefile.include"

.include <bsd.port.mk>
