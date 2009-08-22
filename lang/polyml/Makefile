# New ports collection makefile for:   polyml
# Date created:        09 July 2005
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	polyml
PORTVERSION=	5.2
CATEGORIES=	lang
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}.${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	timbob@bigpond.com
COMMENT=	Fast open-source implementation of Standard ML

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386

PLIST_FILES=	bin/poly		\
		bin/polyimport		\
		lib/libpolymain.a	\
		lib/libpolymain.la	\
		lib/libpolyml.a		\
		lib/libpolyml.la	\
		lib/libpolyml.so	\
		lib/libpolyml.so.1

MAN1=		poly.1 polyimport.1
MANCOMPRESSED=	no

.include <bsd.port.mk>
