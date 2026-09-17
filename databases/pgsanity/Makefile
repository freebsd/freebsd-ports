PORTNAME=	pgsanity
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Check syntax of PostgreSQL SQL files
WWW=		https://github.com/markdrago/pgsanity

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build08>=0.8.19,<0.9.0:devel/py-uv-build08@${PY_FLAVOR}

USES=		pgsql python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	markdrago
USE_PYTHON=	autoplist concurrent pep517
SHEBANG_FILES=	pgsanity/pgsanity.py

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-test:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
