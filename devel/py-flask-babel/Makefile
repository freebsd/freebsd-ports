# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	Flask-Babel
PORTVERSION=	0.10.0
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.io/packages/source/F/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Adds i18n/l10n support to Flask applications

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.10:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.3:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}speaklater>=1.3:devel/py-speaklater

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
