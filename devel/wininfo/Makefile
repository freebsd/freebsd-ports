# New ports collection makefile for:	X Window Information
# Date created:			11 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		wininfo
PORTVERSION=		0.7
PORTREVISION=	7
CATEGORIES=		devel
MASTER_SITES=		http://www.freedesktop.org/software/wininfo/

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A window information utility

USE_XORG=		xext xrender xinerama xrandr xi xfixes xcursor \
			xcomposite x11 xres
USE_GNOME=		gtk20 gnomeprefix pkgconfig 
GNU_CONFIGURE=		yes

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

MAN1=			wininfo.1

.include <bsd.port.mk>
