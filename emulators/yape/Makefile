# New ports collection makefile for:    yape
# Date created:         31.10.2002
# Whom:                 Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	yape
PORTVERSION=	0.32.5
CATEGORIES=	emulators
MASTER_SITES=	http://yape.homeserver.hu/download/
DISTNAME=	${PORTNAME}SDL-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Yet Another Commodore +4 Emulator

USE_SDL=	sdl
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
ALL_TARGET=	yape

PLIST_FILES=	bin/yape
PORTDOCS=	*

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|cpp|h|txt)" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'
	@${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' ${WRKSRC}/Makefile

post-patch:
	@${REINPLACE_CMD} -e "s|sdl-config|${SDL_CONFIG}|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|TAP::TAP|TAP|" ${WRKSRC}/tape.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yape ${PREFIX}/bin

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.SDL ${DOCSDIR}
.endif

.include <bsd.port.mk>
