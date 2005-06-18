# New ports collection makefile for:	blobwars
# Date created:				14 June 2005
# Whom:					Loren M. Lang
#
# $FreeBSD$
#

PORTNAME=	blobwars
DISTVERSION=	1.04-1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=distfiles

MAINTAINER=	lorenl@alzatex.com
COMMENT=	You are the fearless Blob agent, Bob

MAKEFILE=	makefile
MAKE_ENV=	CXX="${CXX}"

USE_X_PREFIX=	yes
USE_SDL=	sdl image mixer ttf
USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/blobwars-1.04

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/makefile
.for f in src/headers.h src/CFileData.cpp src/CPak.cpp src/pak.h
	@${REINPLACE_CMD} -e 's|SDL/SDL\([_a-z]*\)\.h|SDL11/SDL\1.h|' \
		${WRKSRC}/${f}
.endfor

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
