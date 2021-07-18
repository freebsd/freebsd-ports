# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	dataclasses-json
PORTVERSION=	0.5.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easily serialize dataclasses to and from JSON

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marshmallow>=3.3.0<4.0.0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marshmallow-enum>=1.5.1<2.0.0:devel/py-marshmallow-enum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringcase>=1.2.0<2.0.0:devel/py-stringcase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-inspect>=0.4.0:devel/py-typing-inspect@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30700
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dataclasses>=0:devel/py-dataclasses@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
