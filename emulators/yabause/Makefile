# New ports collection makefile for:	yabause
# Date created:		2006-08-23
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yabause
PORTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Sega Saturn system emulator

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	yes
USE_AUTOTOOLS=	automake:19 aclocal:19 autoconf:262

SUB_FILES=	pkg-message
MAN1=	yabause.1

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
