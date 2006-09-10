# New ports collection makefile for:	iiimf-le-chewing
# Date created:		8 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	iiimf-le-chewing
PORTVERSION=	0.0.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	chinese textproc
MASTER_SITES=	http://chewing.csie.net/download/iiimf/
DISTNAME=	${PORTNAME:C/-le-/-/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IIIMF Chewing engine, an intelligent Chinese phonetic input method

BROKEN=		fails to install (dependency problem)
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2006-12-01

LIB_DEPENDS=	chewing.2:${PORTSDIR}/chinese/libchewing
RUN_DEPENDS=	iiimd:${PORTSDIR}/textproc/iiimf-server

USE_XLIB=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"

.include <bsd.port.mk>
