# New ports collection makefile for:	libcddb
# Date created:		Mon Mar  1 00:48:58 EST 2004
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$

PORTNAME=	libcddb
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@ahze.net
COMMENT=	A library to access data on a CDDB server

USE_LIBTOOL_VER=	13
USE_GNOME=	gnometarget lthack gnomehack pkgconfig
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${PATCHDIR}/cddb.h-systypes-patch \
		${PATCHDIR}/cddb_ni.h-systypes-patch
.endif

.include <bsd.port.post.mk>
