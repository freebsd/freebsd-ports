# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	polyml
PORTVERSION=	5.5
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}.${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Fast open-source implementation of Standard ML

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x
USE_GCC=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64

PLIST_FILES=	bin/poly		\
		bin/polyimport		\
		lib/libpolymain.a	\
		lib/libpolymain.la	\
		lib/libpolyml.a		\
		lib/libpolyml.la	\
		lib/libpolyml.so	\
		lib/libpolyml.so.4	\
		man/man1/poly.1.gz	\
		man/man1/polyimport.1.gz

.include <bsd.port.mk>
