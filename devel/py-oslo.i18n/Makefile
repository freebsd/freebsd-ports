# $FreeBSD$

PORTNAME=	oslo.i18n
PORTVERSION=	3.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Oslo i18n library

BUILD_DEPENDS=	${PKGNAMEPREFIX}pbr>=1.6:${PORTSDIR}/devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=1.3:${PORTSDIR}/devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
