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

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools

PLIST_FILES=	lib/${PYTHON_VERSION}/site-packages/YDbf-0.0.1dev_20080514-py2.5.egg

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>
