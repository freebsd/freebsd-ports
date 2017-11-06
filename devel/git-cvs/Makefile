# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	git-cvs
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	devel python

MAINTAINER=	mp39590@gmail.com
COMMENT=	Tool to incrementally import changesets from CVS into Git

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.0:devel/py-nose
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rcsparse>0:devel/py-rcsparse \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ustuehler

USES=		python:2.7 shebangfix
USE_PYTHON=	autoplist distutils
SHEBANG_FILES=	scripts/git-cvs

.include <bsd.port.mk>
