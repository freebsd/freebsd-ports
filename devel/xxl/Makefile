# Ports collection makefile for:        xxl
# Date created:                         28 Aug 2003
# Whom:                                 Robert Schlotterbeck <robert@rs.tarrant.tx.us>
#
# $FreeBSD$
#

PORTNAME=		xxl
PORTVERSION=		1.0.1
CATEGORIES=		devel
MASTER_SITES=		http://www.zork.org/software/

MAINTAINER=		ports@FreeBSD.org
COMMENT=		C and C++ that provides exception handling and asset management

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-threads
INSTALLS_SHLIB=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
