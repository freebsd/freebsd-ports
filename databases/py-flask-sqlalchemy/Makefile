# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	Flask-SQLAlchemy
PORTVERSION=	2.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Adds SQLAlchemy support to Flask

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.10:${PORTSDIR}/www/py-flask \
	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.7:${PORTSDIR}/databases/py-sqlalchemy

USES=	python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
