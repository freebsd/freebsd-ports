PORTNAME=	banihstypos
DISTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.vanheusden.com/banihstypos/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple game to teach you typing, fast
WWW=		http://www.vanheusden.com/banihstypos/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		ncurses tar:tgz

MAKE_ARGS=	LDFLAGS="${LDFLAGS} -lncurses"

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PLIST_FILES=	bin/banihstypos
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/banihstypos ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
