# New ports collection makefile for:  libmad
# Date created:        26 November 2003
# Whom:                Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	libmad
PORTVERSION=	0.15.0b
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.mars.org/pub/mpeg/
MASTER_SITE_SUBDIR=	mad

MAINTAINER=	asa@gascom.ru
COMMENT=	Libmad library (part of MAD project)

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--disable-debugging \
		--enable-sso \
		--enable-accuracy

.include <bsd.port.mk>
