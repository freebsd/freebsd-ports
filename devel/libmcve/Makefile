# New ports collection makefile for:	libmcve
# Date Created:				16 March 2002
# Whom:					Brad House <brad@mcve.com>
#
# $FreeBSD$
#

PORTNAME=	libmcve
PORTVERSION=	4.1
#PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	libmonetra-${PORTVERSION}
MASTER_SITES=	ftp://ftp.mcve.com/pub/libmonetra/

MAINTAINER=	brad@mcve.com
COMMENT=	Library to allow credit card processing through MCVE

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--without-pthread

post-install:
	@${LN} -fs libmcve.so.4 ${PREFIX}/lib/libmcve.so.3

.include <bsd.port.mk>
