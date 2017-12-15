# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty-solitaire
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Play solitaire in your terminal

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	mpereira

USES=		gmake ncurses

PORTDOCS=	*
PLIST_FILES=	bin/ttysolitaire

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttysolitaire ${STAGEDIR}${PREFIX}/bin/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
