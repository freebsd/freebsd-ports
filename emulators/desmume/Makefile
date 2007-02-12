# New ports collection makefile for:	desmume
# Date created:				Wed  7 Feb 2007 21:46:15 CET
# Whom:					Stefan Sperling <stsp@stsp.in-berlin.de>
#
# $FreeBSD$
#

PORTNAME=	desmume
PORTVERSION=	0.6.0
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	stsp@stsp.in-berlin.de
COMMENT=	Nintendo DS emulator

USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GNOME=	gtk20 libglade2

PLIST_FILES=	bin/desmume-glade bin/desmume bin/desmume-cli

.include <bsd.port.mk>
