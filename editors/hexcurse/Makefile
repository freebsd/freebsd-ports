# ex:ts=8
# New ports collection makefile for:	hexcurse
# Date created:			Jun 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hexcurse
PORTVERSION=	1.55
CATEGORIES=	editors
MASTER_SITES=	http://www.jewfish.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A versatile ncurses-based hex editor

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		hexcurse.1
PLIST_FILES=	bin/hexcurse

.include <bsd.port.mk>
