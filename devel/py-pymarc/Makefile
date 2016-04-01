# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pymarc
PORTVERSION=	3.1.1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Read Write And Modify MARC Bibliographic Data

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} test.py

.include <bsd.port.mk>
