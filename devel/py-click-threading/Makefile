# Created by: Christian Geier <geier@lostpackets.de>
# $FreeBSD$

PORTNAME=	click-threading
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	geier@lostpackets.de
COMMENT=	Multithreaded Click apps made easy

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3200
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}futures>=0:devel/py-futures
.endif

.include <bsd.port.post.mk>
