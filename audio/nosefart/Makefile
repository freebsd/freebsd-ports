# New ports collection makefile for:	nosefart
# Date created:		11 October 2000
# Whom:			sethk
#
# $FreeBSD$
#

PORTNAME=	nosefart
PORTVERSION=	1.92
PORTREVISION=	1
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.meowfishies.com/code/

MAINTAINER=	sethk@meowfishies.com
COMMENT=	A player for NES Sound Format (NSF)

USE_GETOPT_LONG=yes
USE_ZIP=	yes
USE_GMAKE=	yes

MAKEFILE=	Makefile.linux
MAKE_ENV=	INSTALL="${INSTALL}" BINGRP=${BINGRP} BINMODE=${BINMODE} \
		BINOWN=${BINOWN} LDFLAGS="${LDFLAGS}"

.include    <bsd.port.mk>
