# Ports collection makefile for:	gom
# Date created:				12 Nov 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gozer
PORTVERSION=	0.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A commandline text rendering utility that creates images from arbitrary text

LIB_DEPENDS=	giblib.1:${PORTSDIR}/graphics/giblib

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-porbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-giblib-prefix=${X11BASE}

MAN1=		gozer.1

.if defined(NOPORTDOCS)
MAKE_ENV=	NO_DOC=yes
.endif

.include <bsd.port.mk>
