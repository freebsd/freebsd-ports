PORTNAME=	aioice
DISTVERSION=	0.12.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Interactive Connectivity Establishment (RFC 5245) in Python
WWW=		https://github.com/aiortc/aioice

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=2.0.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ifaddr>=0.2.0:net/py-ifaddr@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^license = .*|license = { text = "BSD-3-Clause" }|' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
