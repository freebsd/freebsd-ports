PORTNAME=	babel
DISTVERSION=	2.19.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
DISTNAME=	babel-${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Collection of tools for internationalizing Python applications
WWW=		https://babel.pocoo.org/

LICENSE=	BSD-3-Clause Unicode-3.0
LICENSE_COMB=	multi
LICENSE_FILE_BSD-3-Clause=	${WRKSRC}/LICENSE
LICENSE_FILE_Unicode-3.0=	${WRKSRC}/babel/locale-data/LICENSE.unicode

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.27.0:devel/py-hatchling@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freezegun>0:devel/py-freezegun@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	pocoo
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes
PORTDOCS=	docs/*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|~=1|>=1|g' ${WRKSRC}/pyproject.toml

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ${PORTDOCS}
	${CP} -r ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
