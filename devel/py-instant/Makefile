# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	instant
PORTVERSION=	${MMVERSION}.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${MMVERSION}.x/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python module for instant inlining of C and C++ code in Python

LICENSE=	LGPL3

RUN_DEPENDS=	swig3.0:devel/swig30

USES=			python:2.7
USE_PYTHON=		distutils
PYDISTUTILS_PKGNAME=	instant

MMVERSION=	1.2

post-patch:
	@${REINPLACE_CMD} -e \
	's|\[(join("share", "man", "man1"),|\[(join("man", "man1"),|' \
	${WRKSRC}/setup.py

.include <bsd.port.mk>
