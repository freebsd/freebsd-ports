# ex:ts=8
# Ports collection makefile for:	py-reverse
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	reverse
PORTVERSION=	0.5.2
CATEGORIES=	devel python
MASTER_SITES=	LOGILAB/py${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	A set of tools for reverse engineering Python code

BUILD_DEPENDS=	${PYXML}
RUN_DEPENDS=	${PYXML} \
		pytest:${PORTSDIR}/devel/py-logilab-common

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyreverse

.include <bsd.port.mk>
