# ex:ts=8
# Ports collection makefile for:	py-reverse
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	reverse
PORTVERSION=	0.2.3
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.logilab.org/pub/pyreverse/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PYXML}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
