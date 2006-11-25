# New ports collection makefile for:	py-TestGears
# Date created:		2006-01-11
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	TestGears
PORTVERSION=	0.2
CATEGORIES=	devel python
MASTER_SITES=	http://nivi.interfree.it/distfiles/${PORTNAME}/ \
		http://www.turbogears.org/download/eggs/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	nivit@email.it
COMMENT=	Python module to run tests written as simple functions

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
# need to remove the egg
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

SUB_FILES=	pkg-deinstall
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EGG="${PORTNAME}==${PORTVERSION}"

.include <bsd.port.mk>
