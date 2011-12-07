# New ports collection makefile for:	mingw32-libyaml
# Date created:		5 December 2011
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libyaml
PORTVERSION=	0.1.4
CATEGORIES=	devel textproc
MASTER_SITES=	http://pyyaml.org/download/libyaml/
PKGNAMEPREFIX=	mingw32-
DISTNAME=	yaml-${PORTVERSION}
DIST_SUBDIR=	repacked

MAINTAINER=	knu@FreeBSD.org
COMMENT=	The libyaml library cross-compiled for MinGW32

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc \
		${LOCALBASE}/mingw32/include/stdlib.h:${PORTSDIR}/devel/${PKGNAMEPREFIX}bin-msvcrt

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/mingw32
CONFIGURE_ARGS=	--host="mingw32"
CC=		${PKGNAMEPREFIX}gcc
CFLAGS=		-O3	# Override CFLAGS for a cross-build

.include <bsd.port.mk>
