# New ports collection makefile for:	RealTimeBattle
# Date created:				30 June 2000
# Whom:				Dishanker Rajakulendren <draj@oceanfree.net>
#
# $FreeBSD$
#

PORTNAME=	RealTimeBattle
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.lysator.liu.se/realtimebattle/Download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot programming game for UNIX

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-debug

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

.include <bsd.port.post.mk>
