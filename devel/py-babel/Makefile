PORTNAME=	Babel
DISTVERSION=	2.17.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
DISTNAME=	babel-${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Collection of tools for internationalizing Python applications
WWW=		https://babel.pocoo.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freezegun>0:devel/py-freezegun@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	pocoo
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes
PORTDOCS=	docs/*

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ${PORTDOCS}
	${CP} -r ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
