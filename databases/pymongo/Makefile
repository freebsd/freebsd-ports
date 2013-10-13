# Created by: wen@FreeBSD.org
# $FreeBSD$

PORTNAME=	pymongo
PORTVERSION=	2.6.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python driver for MongoDB

LICENSE=	AL2

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_NOEGGINFO=	yes
PYTHON_PY3K_PLIST_HACK=	yes
NO_STAGE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not install on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>
