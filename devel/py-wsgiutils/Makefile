# New ports collection makefile for:	py-wsgiutils
# Date created:         		25 June 2006
# Whom:                 		Jordi Haarman
#
# $FreeBSD$
#

PORTNAME=	wsgiutils
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	devel textproc www python
MASTER_SITES=	http://www.owlfish.com/software/wsgiutils/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WSGIUtils-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility libraries for development of simple WSGI programs

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	WSGIUtils

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYEASYINSTALL_EGG}

.include <bsd.port.mk>
