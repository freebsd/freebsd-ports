# New ports collection makefile for:	libukcprog
# Date created:		30 March 2003
# Whom:			Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	libukcprog
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.mirrorservice.org/sites/ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		ftp://ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://www.i-scream.org/pub/i-scream/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tim@bishnet.net
COMMENT=	Generally useful low level routines

MAN3=		ukcprog.3
DIST_SUBDIR=	i-scream
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=	13
USE_GNOME=	gnomehack gnometarget pkgconfig lthack

.include <bsd.port.mk>
