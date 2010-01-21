# New ports collection makefile for:	msgpack
# Date created:		18 Jan 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	msgpack
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SOURCEFORGE_JP
MASTER_SITE_SUBDIR=	msgpack/45536

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Binary-based efficient data interchange format focused on performance

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GCC=	4.2+

.if ${MACHINE_ARCH} == "i386"
# Mayby not working on i386/i486/i586...
CONFIGURE_ARGS=	CFLAGS="${CFLAGS} -march=i686" CXXFLAGS="${CXXFLAGS} -march=i686"
.endif

.include <bsd.port.mk>
