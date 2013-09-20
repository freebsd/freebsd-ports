# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pygpx
PORTVERSION=	0.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/p/pygpx/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python Module For Parsing GPS Exchange Format (GPX) File

PLIST_SUB=	GPX_INFO=${PYDISTUTILS_EGGINFO}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PKGDISTUTILS_NOEGGINFO=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
