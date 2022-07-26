PORTNAME=	git-prev-next
DISTVERSION=	g20220319
CATEGORIES=	devel

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Git commands for navigating and editing Git commit history

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ridiculousfish
GH_TAGNAME=	6d070d3
SHEBANG_FILES=	${_SCRIPTS}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${_SCRIPTS:S|^|bin/|}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

_SCRIPTS=	git-prev git-next

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${_SCRIPTS} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
