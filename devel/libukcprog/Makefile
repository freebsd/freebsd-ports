# New ports collection makefile for:	libukcprog
# Date created:		30 March 2003
# Whom:			Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	libukcprog
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.mirror.ac.uk/sites/ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://www.mirror.ac.uk/sites/ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		ftp://ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://www.i-scream.org/pub/i-scream/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tim@bishnet.net
COMMENT=	Generally useful low level routines

MAN3=		ukcprog.3
DIST_SUBDIR=	i-scream
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_GNOME=	pkgconfig

.include <bsd.port.mk>
