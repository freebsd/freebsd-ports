# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	testoob
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Testoob is an advanced unit testing framework for PyUnit

OPTIONS_DEFINE=	TWISTED
TWISTED_DESC=	enable running in threads

USES=		tar:bzip2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTWISTED}
USES+=		twisted
.endif

.include <bsd.port.post.mk>
