# New ports collection makefile for:	gok
# Date created:			12 April 2003
# Whom:				Adam Weinberger <adamw@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gok
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	accessibility sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.8
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME On-Screen Keyboard (GOK)

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui atspi libwnck
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/gok/word-complete.c

.include <bsd.port.mk>
