# New ports collection makefile for:	py-flask-babel
# Date created:							2010-09-26
# Whom:									Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Flask-Babel
PORTVERSION=	0.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Adds i18n/l10n support to Flask applications

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.6:${PORTSDIR}/www/py-flask \
	${PYTHON_PKGNAMEPREFIX}Babel>=0.9:${PORTSDIR}/devel/py-babel \
	${PYTHON_PKGNAMEPREFIX}pytz>=2010:${PORTSDIR}/devel/py-pytz \
	${PYTHON_PKGNAMEPREFIX}speaklater>=1.2:${PORTSDIR}/devel/py-speaklater

LICENSE=	BSD

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
