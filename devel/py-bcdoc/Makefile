# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	bcdoc
PORTVERSION=	0.16.0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools to help document botocore-based projects

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.10:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.1.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
