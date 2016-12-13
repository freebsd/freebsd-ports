# Created by: elvstone@gmail.com
# $FreeBSD$

PORTNAME=	sqlalchemy-migrate
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Database schema migrations for SQLAlchemy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.3:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0.7.8:databases/py-sqlalchemy10 \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.4:textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}sqlparse>0:databases/py-sqlparse \
		${PYTHON_PKGNAMEPREFIX}six>=1.7.0:devel/py-six

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
