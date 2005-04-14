# New ports collection makefile for:    hatari
# Date created:         15 March 2004
# Whom:                 Michael Neumann <mneumann@ntecs.de>
#
# $FreeBSD$
#

PORTNAME=	hatari
PORTVERSION=	0.60
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	An Atari ST emulator

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_SDL=	yes

.include <bsd.port.mk>
