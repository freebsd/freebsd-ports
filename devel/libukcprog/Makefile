# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	libukcprog
PORTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.uk.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://ftp.uk.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://dl.ambiweb.de/mirrors/ftp.i-scream.org/%SUBDIR%/ \
		ftp://ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://ftp.i-scream.org/pub/i-scream/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Generally useful low level routines

NO_CDROM=	License (see source) does not permit selling for profit

USE_AUTOTOOLS=	libtool
MAN3=		ukcprog.3
DIST_SUBDIR=	i-scream
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig
USE_GNOME=	lthack

NO_STAGE=	yes
.include <bsd.port.mk>
