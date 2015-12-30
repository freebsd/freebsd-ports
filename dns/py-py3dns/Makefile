# Created by: Mark Linimon <linimon@lonesome.com>
# $FreeBSD$

PORTNAME=	py3dns
PORTVERSION=	3.1.0
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DNS (Domain Name Service) library for Python 3

LICENSE=	CNRI
LICENSE_NAME=	CNRI LICENSE AGREEMENT
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddress>=0:${PORTSDIR}/net/py-ipaddress
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddress>=0:${PORTSDIR}/net/py-ipaddress
.endif

.include <bsd.port.post.mk>
