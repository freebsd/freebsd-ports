# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jaraco.util
PORTVERSION=	10.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	General utility modules that supply commonly-used functionality

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:${PORTSDIR}/devel/py-more-itertools \
		${PYTHON_PKGNAMEPREFIX}jaraco.timing>0:${PORTSDIR}/devel/py-jaraco.timing
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hgtools>0:${PORTSDIR}/devel/py-hgtools

USES=		zip
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
