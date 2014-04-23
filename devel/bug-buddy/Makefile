# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/bug-buddy/Makefile,v 1.86 2010/11/16 18:17:55 kwm Exp $

PORTNAME=	bug-buddy
PORTVERSION=	2.32.0
PORTREVISION=	4
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Bug reporting tool for GNOME 2

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup

USES=		gettext gmake libtool:keepla  pathfix pkgconfig tar:bzip2
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	gnomeprefix intlhack libbonobo \
		gnomedocutils evolutiondataserver
GNOME_DESKTOP_VERSION=2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	bug-buddy.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|' \
		${WRKSRC}/src/bugzilla.c
	@${REINPLACE_CMD} -e 's|libelf.h||g ; \
	    	s|gelf.h||g' \
	    	${WRKSRC}/configure

post-install:
	@${LN} -fs libgnomesegvhandler.so \
		${STAGEDIR}${PREFIX}/lib/gtk-2.0/modules/libgnomebreakpad.so

.include <bsd.port.mk>
