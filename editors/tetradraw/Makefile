# ex:ts=8
# Ports collection makefile for:	tetradraw
# Date created:			1 October 2002
# Whom:				Frederic Cambus
#
# $FreeBSD$
#

PORTNAME=	tetradraw
PORTVERSION=	2.0.2
CATEGORIES=	editors
MASTER_SITES=	ftp://tentacle.dhs.org/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
