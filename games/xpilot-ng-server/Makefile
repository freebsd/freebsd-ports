# New ports collection makefile for:	xpilot-ng
# Date created:			11 Sep 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		xpilot-ng
PORTVERSION=		4.5.4X2
PORTREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://www.hut.fi/~ksoderbl/xpilot/
DISTNAME=		xpilot-${PORTVERSION}

MAINTAINER=		jylefort@brutele.be
COMMENT=		An enhanced version of XPilot

LIB_DEPENDS=		expat:${PORTSDIR}/textproc/expat2

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes

MAN6=			xp-mapedit-ng.6 xp-replay-ng.6 xpilot-ng.6 xpilots-ng.6

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=		--program-suffix=-ng

.include <bsd.port.mk>
