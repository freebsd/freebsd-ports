# Created by: Christian Geier <geier@lostpackets.de>
# $FreeBSD$

PORTNAME=	click-log
PORTVERSION=	0.1.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	geier@lostpackets.de
COMMENT=	Logging integration for Click

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
