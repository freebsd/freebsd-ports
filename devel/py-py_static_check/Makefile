# New ports collection makefile for:	py_static_check
# Date created:		2011-12-20
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	py_static_check
PORTVERSION=	1.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/p/py_static_check
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Statically check your python code

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flakes>=0.5:${PORTSDIR}/devel/py-flakes

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
