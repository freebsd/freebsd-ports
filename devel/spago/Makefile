PORTNAME=	spago
DISTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	https://registry.npmjs.org/spago/-/

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	PureScript package manager and build tool
WWW=		https://github.com/spacchetti/spago/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git \
		purs:lang/purescript

USES=		nodejs:run tar:tgz

WRKSRC=		${WRKDIR}/package
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${PREFIX}/bin/spago \
		${PREFIX}/bin/docs-search-app.js

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bundle.js ${STAGEDIR}${PREFIX}/bin/spago
	${INSTALL_SCRIPT} ${WRKSRC}/bin/docs-search-app.js ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
