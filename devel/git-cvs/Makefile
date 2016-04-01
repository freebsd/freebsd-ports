# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	git-cvs
PORTVERSION=	0.0.1.20151027
CATEGORIES=	devel python

MAINTAINER=	mp39590@gmail.com
COMMENT=	Tool to incrementally import changesets from CVS into Git

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rcsparse>0:devel/py-rcsparse \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ustuehler
GH_TAGNAME=	d068834

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
