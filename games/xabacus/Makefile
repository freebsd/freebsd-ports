# New ports collection makefile for:	xabacus
# Date created:				3 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xabacus
PORTVERSION=	7.1.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.tux.org/pub/tux/bagleyd/xabacus/
MASTER_SITE_SUBDIR=	apps/math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abacus for X Window System

USE_BZIP2=	yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-nas

MAN6=		xabacus.6

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MOTIF)
CONFIGURE_ARGS+=	--without-motif
.else
USE_MOTIF=	yes
.endif

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--without-rplay --with-esound
.else
LIB_DEPENDS+=	rplay.1:${PORTSDIR}/audio/rplay
CONFIGURE_ARGS+=	--with-rplay --without-esound
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/games/|/|g' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
