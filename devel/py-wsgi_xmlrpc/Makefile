# New ports collection makefile for:	py-wsgi_xmlrpc
# Date created:				2008-08-27
# Whom:					Yevgen Drachenko <geka@sippysoft.com>
#
# $FreeBSD$
#

PORTNAME=	wsgi_xmlrpc
PORTVERSION=	0.2.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/_/-/}-${PORTVERSION}

MAINTAINER=	geka@sippysoft.com
COMMENT=	WSGI application for a simple XMLRPC method dispatching

LICENSE=	ASL

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
