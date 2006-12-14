# New ports collection makefile for:	py-nose
# Date created:		14 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	nose
PORTVERSION=	0.9.1
CATEGORIES=	devel python
MASTER_SITES=	http://somethingaboutorange.com/mrl/projects/nose/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dryice@dryice.name
COMMENT=	A discovery-based unittest extension

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS=}

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
NOSEVER?=	${PORTVERSION}
PYTHONVER?=	${_PYTHON_VERSION}
PLIST_SUB=	NOSEVER=${NOSEVER} \
		PYTHONVER=${PYTHONVER}

.include <bsd.port.mk>
