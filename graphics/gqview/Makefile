# New ports collection makefile for:	gqview
# Date Created:				27 Oct 1998
# Whom:					Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqview
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another gtk-based graphic file viewer

USE_X_PREFIX=	yes
USE_GNOME=	gdkpixbuf
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	213
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-gnome

CONFLICTS=	gqview-devel-1.3.*

MAN1=		gqview.1

post-patch:
	@${REINPLACE_CMD} -e 's|INCLUDED_LIBINTL=yes|INCLUDED_LIBINTL=no|g' \
		${WRKSRC}/aclocal.m4

post-install:
	${MKDIR} ${PREFIX}/share/gnome/pixmaps
	${MKDIR} ${PREFIX}/share/gnome/apps/Graphics
	${INSTALL_DATA} ${WRKSRC}/gqview.png ${PREFIX}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gqview.desktop ${PREFIX}/share/gnome/apps/Graphics

.include <bsd.port.mk>
