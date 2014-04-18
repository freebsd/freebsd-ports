# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	xmltodict
PORTVERSION=	0.9.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@FreeBSD.org
COMMENT=	XML parser that returns python dictionaries

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose:${PORTSDIR}/devel/py-nose

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

regression-test: build
	@cd ${WRKSRC} && nosetests

.include <bsd.port.mk>
