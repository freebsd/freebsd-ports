# New ports collection makefile for:	py-wsgiutils
# Date created:         		25 June 2006
# Whom:                 		Jordi Haarman
#
# $FreeBSD$
#

PORTNAME=	wsgiutils
PORTVERSION=	0.7
CATEGORIES=	devel textproc www python
MASTER_SITES=	http://www.owlfish.com/software/wsgiutils/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WSGIUtils-${PORTVERSION}

MAINTAINER=	j.haarman@synantics.com
COMMENT=	Utility libraries for development of simple WSGI programs

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		PYTHON_VERSION_NR=${_PYTHON_PORTBRANCH}

.include <bsd.port.mk>
