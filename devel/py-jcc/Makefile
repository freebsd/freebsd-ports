# New ports collection makefile for:	jcc
# Date created:		16 May 2008
# Whom:			clsung@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	jcc
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	devel java python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=	source/J/JCC
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	JCC-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	C++ code generator for calling Java from C++/Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	JCC
USE_JAVA=	yes
JAVA_VERSION=	1.4+

JCC_INCLUDES=	'${JAVA_HOME}/include;${JAVA_HOME}/include/freebsd'
JCC_CFLAGS=	-pipe
JCC_LFLAGS=	'-L${JAVA_HOME}/jre/lib/${ARCH};-ljava'

MAKE_ENV+=	JCC_INCLUDES=${JCC_INCLUDES} JCC_CFLAGS=${JCC_CFLAGS} JCC_LFLAGS=${JCC_LFLAGS} JCC_ARGSEP=";"

.include <bsd.port.mk>
