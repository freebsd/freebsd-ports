# New ports collection makefile for:	gok
# Date created:			12 April 2003
# Whom:				Adam Weinberger <adamw@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gok
PORTVERSION=	1.0.3
CATEGORIES=	accessibility sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME On-Screen Keyboard (GOK)

LIB_DEPENDS=	gnomespeech.7:${PORTSDIR}/accessibility/gnomespeech

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui atspi libwnck
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GCONF_SCHEMAS=	gok.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/gok/word-complete.c

.include <bsd.port.mk>
