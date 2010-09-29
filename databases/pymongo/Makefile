# Ports collection makefile for:	pymongo
# Date created:				23 Nov, 2009
# Whom:					wen@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	pymongo
PORTVERSION=	1.9
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python driver for MongoDB

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not install on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>
