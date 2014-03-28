# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	ming
PORTREVISION=	1
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module for Ming which allows you to create Flash 4/5 movies

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

CONFIGURE_ARGS=	--enable-python
PYDISTUTILS_AUTOPLIST=	yes
USE_PYDISTUTILS=yes
USE_PYTHON=	2

BUILD_WRKSRC=	${WRKSRC}/py_ext
INSTALL_WRKSRC=	${WRKSRC}/py_ext
PATCH_WRKSRC=	${WRKSRC}/py_ext
PATCHDIR=	${.CURDIR}/files
PLIST=		${NONEXISTENT}

MASTERDIR=	${.CURDIR}/../../graphics/ming
SLAVEPORT=	py

.include "${MASTERDIR}/Makefile"
