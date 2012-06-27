# New ports collection makefile for:	py-publicsuffix
# Date created:		22 June 2012
# Whom:			Dmitry Pryadko <d.pryadko@rambler-co.ru>
#
# $FreeBSD$
#

PORTNAME=	publicsuffix
PORTVERSION=	1.0.2
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	d.pryadko@rambler-co.ru
COMMENT=	Get public suffix of domain name from Public Suffix List

LICENSE=	MIT

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/publicsuffix.py \
		%%PYTHON_SITELIBDIR%%/publicsuffix.pyc \
		%%PYTHON_SITELIBDIR%%/publicsuffix.pyo \
		%%PYTHON_SITELIBDIR%%/publicsuffix.txt

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
