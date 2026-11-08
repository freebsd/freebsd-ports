PORTNAME=	arpy
DISTVERSION=	2.4.0
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	arpy is a library for accessing the archive files and reading the contents
WWW=		https://github.com/viraptor/arpy

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

post-patch:
	@${REINPLACE_CMD} '/license-files/d; s|^license = "BSD-2-Clause"|license = { text = "BSD-2-Clause" }|; s|77|63|g' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
