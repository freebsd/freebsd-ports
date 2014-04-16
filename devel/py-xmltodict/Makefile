# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	xmltodict
PORTVERSION=	0.8.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	XML parser that returns python dictionaries

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose:${PORTSDIR}/devel/py-nose

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

regression-test: build
	@cd ${WRKSRC} && nosetests

.include <bsd.port.mk>
