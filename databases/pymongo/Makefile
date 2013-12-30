# Created by: wen@FreeBSD.org
# $FreeBSD$

PORTNAME=	pymongo
PORTVERSION=	2.6.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python driver for MongoDB

LICENSE=	APACHE20

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not install on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>
