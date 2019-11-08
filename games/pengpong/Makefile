# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	pengpong
PORTVERSION=	0.3
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}-linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform pong game written in SDL

USES=		perl5 sdl
USE_SDL=	image sdl
NO_WRKSUBDIR=	yes
USE_PERL5=	build

DATAFILES=	24P_Copperplate_Blue.png ball.tga logo.jpg \
		paddle.tga red.png

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${REINPLACE_CMD} -i '' -e 's|/usr/local/share/games/pengpong|${DATADIR}|' \
		${WRKSRC}/files.h
	@${REINPLACE_CMD} -i '' -e 's|V 0.2|V ${PORTVERSION}|' ${WRKSRC}/pengpong.cpp

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/pengpong ${STAGEDIR}${PREFIX}/bin
.for files in ${DATAFILES}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${files} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
