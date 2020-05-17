# $FreeBSD$

PORTNAME=	oslo.serialization
PORTVERSION=	2.29.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Oslo Serialization library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.5.2:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2013.6:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.12:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# oslo.serialization 3.0.0+ requires Python 3.6+
PORTSCOUT=	limit:^2\.

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.utils3>=3.33.0:devel/py-oslo.utils3@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
