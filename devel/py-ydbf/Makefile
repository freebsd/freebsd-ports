# New ports collection makefile for:   ydbf
# Date created:        10 May 2009
# Whom:                Andrey Polyakov <andrey.polyakov@unix.net>
#
# $FreeBSD$
#

PORTNAME=	ydbf
PORTVERSION=	0.0.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/Y/YDbf/
DISTNAME=	YDbf-0.0.1dev-20080514

MAINTAINER=	andrey.polyakov@unix.net
COMMENT=	Yelded DBF reader/writer for Python

PLIST_FILES=	${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/${PYEASYINSTALL_EGG}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_PKGNAME=	YDbf
PYDISTUTILS_PKGVERSION=	0.0.1dev_20080514

.include <bsd.port.mk>
