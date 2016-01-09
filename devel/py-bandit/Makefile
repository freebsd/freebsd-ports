# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	bandit
PORTVERSION=	0.16.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Tool for finding common security issues in Python code

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:${PORTSDIR}/devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3.11:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.5.0:${PORTSDIR}/devel/py-stevedore

MAKE_ENV+=	PBR_VERSION=${PORTVERSION}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
