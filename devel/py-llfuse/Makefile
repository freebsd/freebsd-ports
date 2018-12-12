# $FreeBSD$

PORTNAME=	llfuse
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	stdin@niklaas.eu
COMMENT=	Python bindings for low-level FUSE API

LICENSE=	LGPL20+

BROKEN_powerpc64=	Does not build: error: conversion to mode_t from int may alter its value

USES=		compiler:c++11-lang fuse pkgconfig python tar:bz2
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/llfuse.so

.include <bsd.port.mk>
