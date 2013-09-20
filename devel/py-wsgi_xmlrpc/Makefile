# Created by: Yevgen Drachenko <geka@sippysoft.com>
# $FreeBSD$

PORTNAME=	wsgi_xmlrpc
PORTVERSION=	0.2.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/_/-/}-${PORTVERSION}

MAINTAINER=	geka@sippysoft.com
COMMENT=	WSGI application for a simple XMLRPC method dispatching

LICENSE=	AL2

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
.include <bsd.port.mk>
