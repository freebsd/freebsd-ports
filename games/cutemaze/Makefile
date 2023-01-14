PORTNAME=	cutemaze
PORTVERSION=	1.3.2
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Simple, top-down game in which mazes are randomly generated
WWW=		https://gottcode.org/cutemaze/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang gl qt:6 tar:bzip2
USE_GL=		opengl
USE_QT=		base svg tools:build

PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
