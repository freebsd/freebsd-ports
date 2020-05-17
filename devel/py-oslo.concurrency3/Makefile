# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	oslo.concurrency
PORTVERSION=	3.31.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Oslo Concurrency library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}fasteners>=0.7.0:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# oslo.concurrency 4.0.0+ requires Python 3.6+
PORTSCOUT=	limit:^3\.

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.config7>=5.2.0:devel/py-oslo.config7@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n3>=3.15.3:devel/py-oslo.i18n3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils3>=3.33.0:devel/py-oslo.utils3@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.config>=5.2.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
