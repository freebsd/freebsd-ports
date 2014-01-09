# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	dogpile.cache
PORTVERSION=	0.5.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Caching front-end based on the Dogpile lock

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dogpile.core>0:${PORTSDIR}/devel/py-dogpile.core \
		${PYTHON_PKGNAMEPREFIX}gdbm>0:${PORTSDIR}/databases/py-gdbm

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
