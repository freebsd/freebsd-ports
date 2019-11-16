# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gogrepo
PORTVERSION=	0.3a
PORTREVISION=	3
CATEGORIES=	games net

MAINTAINER=	se@FreeBSD.org
COMMENT=	Batch downloader for (linux,mac,windows) games distributed by GOG.com

LICENSE=	GPLv3+

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/html5lib/html5parser.py:www/py-html5lib \
		html2text:textproc/py-html2text

USE_GITHUB=	yes
GH_ACCOUNT=	eddie3
GH_TAGNAME=	2cd3ac4

USES=		python shebangfix
SHEBANG_FILES=	gogrepo.py

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/gogrepo
PORTDOCS=	README.md

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/gogrepo.py ${STAGEDIR}${PREFIX}/bin/gogrepo

do-install-DOCS-on:
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
