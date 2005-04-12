# New ports collection makefile for:	xabacus
# Date created:				3 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xabacus
PORTVERSION=	7.0.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.tux.org/pub/tux/bagleyd/xabacus/
MASTER_SITE_SUBDIR=	apps/math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abacus for X Window System

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN6=		xabacus.6

.if defined(WITHOUT_MOTIF)
CONFIGURE_ARGS+=	--without-motif
.else
USE_MOTIF=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/games/|/|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
