# New ports collection makefile for:	py-simplejson
# Date created:				25 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	simplejson
PORTVERSION=	1.4
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/s/simplejson/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Simplejson is a simple, fast, extensible JSON encoder/decoder

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
