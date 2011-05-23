# New ports collection makefile for:	re2
# Date created:		2010-09-01
# Whom:			Julien Laffaye <kimelto@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	re2
PORTVERSION=	20110522
CATEGORIES=	devel
MASTER_SITES=	http://jlaffaye.net/distfiles/ \
		http://laffaye.free.fr/distfiles/

MAINTAINER=	kimelto@gmail.com
COMMENT=	A fast C++ regex library

LICENSE=	BSD

USE_LDCONFIG=	yes
USE_GMAKE=	yes
MAKE_ENV=	prefix=${PREFIX}
MAKE_ARGS+=	-e
CC=		${CXX}

.include <bsd.port.mk>
