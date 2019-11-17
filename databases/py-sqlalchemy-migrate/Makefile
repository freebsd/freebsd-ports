# Created by: elvstone@gmail.com
# $FreeBSD$

PORTNAME=	sqlalchemy-migrate
PORTVERSION=	0.13.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Database schema migrations for SQLAlchemy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.3:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=0.7.8:databases/py-sqlalchemy12@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.4:textproc/py-Tempita@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>0:databases/py-sqlparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.7.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=1.3:devel/py-pbr@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
