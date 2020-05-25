# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlalchemy-utils
PORTVERSION=	0.36.6
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLAlchemy-Utils-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Various utility functions for SQLAlchemy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy13>=1.0:databases/py-sqlalchemy13@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ANYJSON ARROW BABEL COLOR ENCRYPTED INTERVALS IPADDRESS PASSWORD PENDULUM PHONE TIMEZONE URL
ANYJSON_DESC=	JSON support
ARROW_DESC=	Arrow type support
BABEL_DESC=	Babel locale type support
COLOR_DESC=	Color type support
ENCRYPTED_DESC=	Encrypted type support
INTERVALS_DESC=	Interval operators support
IPADDRESS_DESC=	IP address type support
PASSWORD_DESC=	Password type support
PENDULUM_DESC=	Pendulum Date/DateTime support
PHONE_DESC=	Phone number type support
TIMEZONE_DESC=	Timezone support
URL_DESC=	URL type support

ANYJSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyjson>=0.3.3:devel/py-anyjson@${PY_FLAVOR}
ARROW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arrow>=0.3.4:devel/py-arrow@${PY_FLAVOR}
BABEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babel>=1.3:devel/py-babel@${PY_FLAVOR}
COLOR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colour>=0.0.4:graphics/py-colour@${PY_FLAVOR}
ENCRYPTED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0.6:security/py-cryptography@${PY_FLAVOR}
INTERVALS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}intervals>=0.7.1:net/py-intervals@${PY_FLAVOR}
PASSWORD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}passlib>=1.6<2.0:security/py-passlib@${PY_FLAVOR}
PENDULUM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pendulum>=2.0.5:devel/py-pendulum@${PY_FLAVOR}
PHONE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}phonenumbers>=5.9.2:devel/py-phonenumbers@${PY_FLAVOR}
TIMEZONE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR}
URL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}furl>=0.4.1:devel/py-furl@${PY_FLAVOR}

.include <bsd.port.mk>
