# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	jmespath
PORTVERSION=	0.0.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexey@renatasystems.org
COMMENT=	JSON Matching Expressions

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.4:${PORTSDIR}/devel/py-ply

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
