# Created by: Jordi Haarman
# $FreeBSD$

PORTNAME=	wsgiutils
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	devel textproc www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WSGIUtils-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility libraries for development of simple WSGI programs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:2.7
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e '/data_files/d' ${WRKSRC}/setup.py

.include <bsd.port.mk>
