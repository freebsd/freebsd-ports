# $FreeBSD$

PORTNAME=	black
DISTVERSION=	18.3a1
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	neel@neelc.org
COMMENT=	Python code formatter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypandoc>0:textproc/py-pypandoc@${FLAVOR} # pypandoc is optional, but recommended

USES=		python:3.6+
USE_PYTHON=	distutils autoplist concurrent
NO_ARCH=	yes

.include <bsd.port.mk>
