# New ports collection makefile for:	Atlas
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	Atlas
PORTVERSION=	0.4.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ecs.soton.ac.uk/pub/worldforge/acorn/0.3/src/ \
		http://kafka.i-site.com/~novalis/mirrors/acorn/0.3/src/ \

MAINTAINER=	lehmann@ans-netz.de

LIB_DEPENDS=	sigc.1:${PORTSDIR}/devel/libsigc++ \
		SDL-1.1.3:${PORTSDIR}/devel/sdl12

USE_NEWGCC=	YES
USE_LIBTOOL=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}

.include <bsd.port.mk>
