# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	rpyc
PORTVERSION=	4.1.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Remote Python Call

LICENSE=	MIT

USES=		python

OPTIONS_DEFINE=	PLUMBUM
OPTIONS_DEFAULT=PLUMBUM

PLUMBUM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plumbum>0:sysutils/py-plumbum@${PY_FLAVOR}
PLUMBUM_DESC=	Required for features like rpyc_classic.py and zero deploy

NO_ARCH=	yes
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
