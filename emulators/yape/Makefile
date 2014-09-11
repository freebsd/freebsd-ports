# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	yape
PORTVERSION=	0.32.5
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://yape.homeserver.hu/download/
DISTNAME=	${PORTNAME}SDL-${PORTVERSION}

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Yet Another Commodore +4 Emulator

USE_SDL=	sdl
USES=		gmake
NO_WRKSUBDIR=	yes
ALL_TARGET=	yape

PLIST_FILES=	bin/yape
PORTDOCS=	README.SDL

OPTIONS_DEFINE=	DOCS

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|cpp|h|txt)" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'
	@${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' ${WRKSRC}/Makefile

post-patch:
	@${REINPLACE_CMD} -e "s|sdl-config|${SDL_CONFIG}|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|TAP::TAP|TAP|" ${WRKSRC}/tape.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yape ${STAGEDIR}${PREFIX}/bin

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.SDL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
