# New ports collection makefile for:	edb
# Date created:		10/16/2000
# Whom:			Brandon Fosdick <bfoz@glue.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	edb
PORTVERSION=	1.0.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ishmael27@home.com

INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-compat185 \
		--enable-dump185 --enable-cxx

post-install:
	@strip ${PREFIX}/lib/libedb.so.1

.include <bsd.port.mk>
