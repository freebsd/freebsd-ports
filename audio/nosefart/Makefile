# New ports collection makefile for:	nosefart
# Date created:		11 October 2000
# Whom:			sethk
#
# $FreeBSD$
#

PORTNAME=	nosefart
PORTVERSION=	1.92
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.meowfishies.com/code/

MAINTAINER=	sethk@meowfishies.com

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_ZIP=	yes
USE_GMAKE=	yes

MAKEFILE=	Makefile.linux
MAKE_ENV+=	INSTALL=${INSTALL} BINGRP=${BINGRP} BINMODE=${BINMODE} \
		BINOWN=${BINOWN}

.include    <bsd.port.mk>
