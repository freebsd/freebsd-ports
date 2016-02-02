# Created by: Mark Linimon <linimon@lonesome.com>
# $FreeBSD$

PORTNAME=	py3dns
PORTVERSION=	3.1.0
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python 3 DNS library

LICENSE=	CNRI
LICENSE_NAME=	CNRI LICENSE AGREEMENT
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:${PORTSDIR}/devel/py-pytest

USES=		python:3.2+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} == 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddress>=0:${PORTSDIR}/net/py-ipaddress
.elif ${PYTHON_REL} <= 3200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddr>=0:${PORTSDIR}/devel/py-ipaddr
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.post.mk>
