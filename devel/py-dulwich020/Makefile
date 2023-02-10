PORTNAME=	dulwich
PORTVERSION=	0.20.50
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	020

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Git Library
WWW=		https://www.dulwich.io/ \
		https://github.com/jelmer/dulwich

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.25,1:net/py-urllib3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastimport>=0:devel/py-fastimport@${PY_FLAVOR}

USES=		cpe python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CPE_VENDOR=	dulwich_project

PORTSCOUT=	limit:^0\.20\.

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
