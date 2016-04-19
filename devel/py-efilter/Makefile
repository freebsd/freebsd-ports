# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	efilter
PORTVERSION=	1453815385
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	EFILTER query language

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>=2011:devel/py-pytz

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}

.include <bsd.port.mk>
