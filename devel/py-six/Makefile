# New ports collection makefile for:	six
# Date created:				15 Nov 2011
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	six
PORTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Python 2 and 3 compatibility utilities

LICENSE=	MIT

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/six.py \
		%%PYTHON_SITELIBDIR%%/six.pyc \
		%%PYTHON_SITELIBDIR%%/six.pyo

.include <bsd.port.mk>
