# New ports collection makefile for:	tide
# Date created:				16 October 2000
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	tide
PORTVERSION=	1.4
CATEGORIES=	devel
MASTER_SITES= 	http://www.t3x.org/Compiler/ \
		http://www.homepages.de/home/nmh/T3X/Compiler/
DISTNAME=	tide-${PORTVERSION:S/.//g}

MAINTAINER=	nmh@t3x.org

BUILD_DEPENDS=	tx:${PORTSDIR}/lang/t3x
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_ENV+=	T3XDIR=/usr/local/t3x/r6

.include <bsd.port.mk>
