# $FreeBSD$

PORTNAME=	azure-cosmos
PORTVERSION=	3.1.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Azure Cosmos Python SDK

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.6:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-extract:
	@${RM} -r ${WRKSRC}/samples ${WRKSRC}/doc

.include <bsd.port.mk>
