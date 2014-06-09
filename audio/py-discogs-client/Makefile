# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	discogs-client
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Python interface to Discogs website

LICENSE=	BSD

RUN_DEPENDS=    ${PYTHON_PKGNAMEPREFIX}requests1>=1.0.0:${PORTSDIR}/www/py-requests1

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
