# Ports collection makefile for:	gom
# Date created:				12 Nov 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gozer
PORTVERSION=	0.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	ishmael27x@yahoo.com

LIB_DEPENDS=	giblib.1:${PORTSDIR}/graphics/giblib

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-porbld-freebsd${OSREL}

.if defined(NOPORTDOCS)
MAKE_ENV=	NO_DOC=yes
.endif

MAN1=		gozer.1

.include <bsd.port.mk>
