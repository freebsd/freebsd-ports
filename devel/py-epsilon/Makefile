# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	epsilon
PORTVERSION=	0.7.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Epsilon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of Python utility modules used by DivMod projects

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:security/py-openssl

CONFLICTS=	brlcad-[0-9]*
USES=		python twisted
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
