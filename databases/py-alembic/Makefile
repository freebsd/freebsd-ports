# $FreeBSD$

PORTNAME=	alembic
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Database migration tool for SQLAlchemy

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0:textproc/py-mako@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-editor>=0:devel/py-python-editor@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
