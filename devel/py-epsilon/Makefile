# New ports collection makefile for:	py-epsilon
# Date created:				10 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	epsilon
PORTVERSION=	0.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Epsilon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Epsilon is a set of Python utility modules used by DivMod projects

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl

CONFLICTS=	brlcad-[0-9]*
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Epsilon
USE_TWISTED=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
