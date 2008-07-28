# New ports collection makefile for:	blobwars
# Date created:				14 June 2005
# Whom:					Loren M. Lang
#
# $FreeBSD$
#

PORTNAME=	blobwars
DISTVERSION=	1.08-1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=distfiles

MAINTAINER=	lorenl@north-winds.org
COMMENT=	You are the fearless Blob agent, Bob

MAKEFILE=	makefile

USE_GETTEXT=	yes
USE_SDL=	sdl image mixer ttf
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/blobwars-${DISTVERSION:C/-[0-9]$//}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/makefile

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
