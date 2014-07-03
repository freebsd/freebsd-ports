# Created by: Frank W. Josellis <frank@dynamical-systems.org>
# $FreeBSD$

PORTNAME=	sdlCC
PORTVERSION=	0.0.0
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://chinesecheckers.vegard2.no/ \
		http://jcatki.no-ip.org/files/

MAINTAINER=	games@FreeBSD.org
COMMENT=	Extensible Chinese checkers game using SDL

USES=		libtool:keepla # ltdl used, .la may be needed to load plugins
USE_SDL=	image mixer sdl
GNU_CONFIGURE=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure ${WRKSRC}/libltdl/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/players/README ${STAGEDIR}${DOCSDIR}/README.players

.include <bsd.port.mk>
