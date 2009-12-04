# New ports collection makefile for:	fceu
# Date Created:		10 Mov 2002
# Whom:			HIYAMA Takeshi <gibbon@cocoa.freemail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	fceux
PORTVERSION=	2.1.1
CATEGORIES=	emulators
MASTER_SITES=	SF/fceultra/Source%20Code/${PORTVERSION}%20src/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	chris@officialunix.com
COMMENT=	A portable NES/Famicom emulator based on Bero's original FCE

USE_BZIP2=	yes
USE_SCONS=	yes
USE_SDL=	sdl
USE_DOS2UNIX=	yes
USE_LUA=	yes

WRKSRC=		${WRKDIR}/fceu

BUILD_DEPENDS+=	zenity:${PORTSDIR}/x11/zenity

MAN6=		fceux.6

.include <bsd.port.pre.mk>

post-extract:
       ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' \
		${WRKSRC}/src/drivers/common/vidblit.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/fceux ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/documentation/fceux.6 ${PREFIX}/man/man6
	${RM} ${WRKSRC}/documentation/fceux.6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
