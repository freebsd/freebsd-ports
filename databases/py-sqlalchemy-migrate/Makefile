# Created by: elvstone@gmail.com
# $FreeBSD$

PORTNAME=	sqlalchemy-migrate
PORTVERSION=	0.10.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Database schema migrations for SQLAlchemy

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8.1:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=1.0.13:databases/py-sqlalchemy10 \
		${PYTHON_PKGNAMEPREFIX}Tempita>0:textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
