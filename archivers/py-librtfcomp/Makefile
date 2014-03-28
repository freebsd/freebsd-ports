# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTREVISION=	1
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for library for handling compressed RTF documents

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/bin/pyrexc:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	librtfcomp.so:${PORTSDIR}/archivers/librtfcomp

USE_PYTHON=	2

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python
PLIST=		${NONEXISTENT}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pyrtfcomp.a \
		%%PYTHON_SITELIBDIR%%/pyrtfcomp.la \
		%%PYTHON_SITELIBDIR%%/pyrtfcomp.so

MASTERDIR=	${.CURDIR}/../librtfcomp
SLAVEPORT=	py

.include "${MASTERDIR}/Makefile"
