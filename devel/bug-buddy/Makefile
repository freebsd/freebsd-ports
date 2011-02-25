# New ports collection makefile for:	bugbuddy2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/bug-buddy/Makefile,v 1.86 2010/11/16 18:17:55 kwm Exp $
#

PORTNAME=	bug-buddy
PORTVERSION=	2.32.0
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A bug reporting tool for GNOME 2

LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libbonobo \
		gnomedocutils evolutiondataserver
GNOME_DESKTOP_VERSION=2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	bug-buddy.schemas

MAN1=		bug-buddy.1

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|' \
		${WRKSRC}/src/bugzilla.c
	@${REINPLACE_CMD} -e 's|libelf.h||g ; \
	    	s|gelf.h||g' \
	    	${WRKSRC}/configure

post-install:
	@${LN} -fs ${PREFIX}/lib/gtk-2.0/modules/libgnomesegvhandler.so \
		${PREFIX}/lib/gtk-2.0/modules/libgnomebreakpad.so

.include <bsd.port.mk>
