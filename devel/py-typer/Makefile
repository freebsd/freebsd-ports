# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	typer
PORTVERSION=	0.3.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for building CLI applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7.1.1<7.2.0:devel/py-click@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ALL
OPTIONS_DEFAULT=ALL
ALL_DESC=	All dependencies

ALL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.3<0.5.0:devel/py-colorama@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}shellingham>=1.3.0<2.0.0:devel/py-shellingham@${PY_FLAVOR}

.include <bsd.port.mk>
