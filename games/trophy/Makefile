# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	trophy
PORTVERSION=	2.0.4
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Single player racing game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libclanCore.so:devel/clanlib1

USES=		pkgconfig localbase
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "/^icondir =/s,icons,pixmaps," \
		${WRKSRC}/resources/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
