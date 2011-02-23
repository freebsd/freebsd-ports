# New ports collection makefile for:	py-flask-sqlalchemy
# Date created:		2010-09-26
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Flask-SQLAlchemy
PORTVERSION=	0.11
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Adds SQLAlchemy support to Flask

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.6:${PORTSDIR}/www/py-flask \
	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.6:${PORTSDIR}/databases/py-sqlalchemy

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
