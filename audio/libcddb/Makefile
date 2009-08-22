# New ports collection makefile for:	libcddb
# Date created:		Mon Mar  1 00:48:58 EST 2004
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#    $MCom: ports-stable/audio/libcddb/Makefile,v 1.1 2005/08/09 04:21:26 ahze Exp $
#      $Id: Makefile 17 2006-10-17 02:09:55Z buhnux $

PORTNAME=	libcddb
PORTVERSION=	1.3.0
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A library to access data on a CDDB server

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gnomehack pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--without-cdio
CONFIGURE_ENV=	CPPFLAGS="-DICONV_CONST=\"const\""

.include <bsd.port.mk>
