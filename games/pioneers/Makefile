# New ports collection makefile for:	gnocotan
# Date created:				22nd July 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pioneers
PORTVERSION=	0.9.61
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	pio

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	An Internet playable version of the Settlers of Catan for GNOME/GTK+

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN6=		pioneers.6 pioneers-server-gtk.6 pioneers-server-console.6 \
		pioneersai.6 pioneers-meta-server.6

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/bin/scrollkeeper-config)
USE_GNOME+=	libgnome
INSTALLS_OMF=	yes
PLIST_SUB+=	LIBGNOME=""
.else
PLIST_SUB+=	LIBGNOME="@comment "
.endif

.include <bsd.port.post.mk>
