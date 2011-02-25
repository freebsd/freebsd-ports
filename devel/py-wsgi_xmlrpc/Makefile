# New ports collection makefile for:	py-wsgi_xmlrpc
# Date created:				2008-08-27
# Whom:					Yevgen Drachenko <geka@sippysoft.com>
#
# $FreeBSD$
#

PORTNAME=	wsgi_xmlrpc
PORTVERSION=	0.2.5p
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=   http://devel.sippysoft.com:8080/~bamby/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	wsgi-xmlrpc-0.2.5pre

MAINTAINER=	geka@sippysoft.com
COMMENT=	WSGI application for a simple XMLRPC method dispatching

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGVERSION= ${PORTVERSION:S/p/pre/}

.include <bsd.port.mk>
