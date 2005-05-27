# New ports collection makefile for:	iiimf-le-chewing
# Date created:		8 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	iiimf-le-chewing
PORTVERSION=	0.0.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	chinese textproc
MASTER_SITES=	http://chewing.csie.net/download/iiimf/
DISTNAME=	${PORTNAME:C/-le-/-/}-${PORTVERSION}

MAINTAINER=	kcwu@csie.org
COMMENT=	IIIMF Chewing engine, an intelligent Chinese phonetic input method

LIB_DEPENDS=	chewing.2:${PORTSDIR}/chinese/libchewing
RUN_DEPENDS=	iiimd:${PORTSDIR}/textproc/iiimf-server

USE_XLIB=	yes
USE_ICONV=	yes
USE_LIBTOOL_VER=15
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"

.include <bsd.port.mk>
