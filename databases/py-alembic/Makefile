# $FreeBSD$

PORTNAME=	alembic
PORTVERSION=	0.8.6
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Database migration tool for SQLAlchemy

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.7.3:databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}mako>=0:textproc/py-mako

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
