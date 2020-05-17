# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	keystonemiddleware
PORTVERSION=	8.0.0
PORTREVISION=	10
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	8

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Middleware for OpenStack Identity

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.14.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.7.1:www/py-webob@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# keystonemiddleware 9.0.0+ requires Python 3.6+
PORTSCOUT=	limit:^8\.

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}keystoneauth13>=3.12.0:devel/py-keystoneauth13@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.cache1>=1.26.0:devel/py-oslo.cache1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config7>=5.2.0:devel/py-oslo.config7@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context2>=2.19.2:devel/py-oslo.context2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n3>=3.15.3:devel/py-oslo.i18n3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log3>=3.36.0:devel/py-oslo.log3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization2>=2.18.0:devel/py-oslo.serialization2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils3>=3.33.0:devel/py-oslo.utils3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycadf2>=1.1.0:devel/py-pycadf2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient3>=3.20.0:net/py-python-keystoneclient3@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}keystoneauth1>=3.12.0:devel/py-keystoneauth1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.cache>=1.26.0:devel/py-oslo.cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.2.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.19.2:devel/py-oslo.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.36.0:devel/py-oslo.log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycadf>=1.1.0:devel/py-pycadf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=3.20.0:net/py-python-keystoneclient@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
