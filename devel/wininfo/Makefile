# New ports collection makefile for:	X Window Information
# Date created:			11 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		wininfo
PORTVERSION=		0.5
PORTREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		http://www.freedesktop.org/Software/wininfo/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A window information utility

BROKEN=			Checksum mismatch

USE_X_PREFIX=		yes
USE_GNOME=		gtk20 gnomeprefix
GNU_CONFIGURE=		yes

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=			wininfo.1

.include <bsd.port.mk>
