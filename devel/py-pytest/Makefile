# $FreeBSD$

PORTNAME=	pytest
PORTVERSION=	2.5.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Cross-project testing tool for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylib>=1.4.19:${PORTSDIR}/devel/py-pylib

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

TEST_DEPENDS:=		${RUN_DEPENDS}

regression-test: build
	@cd ${WRKSRC} && PYTHONPATH=${WRKSRC} ${PYTHON_CMD} pytest.py --ignore=doc/ja

.include <bsd.port.mk>
