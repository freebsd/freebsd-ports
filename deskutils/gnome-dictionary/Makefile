# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-dictionary/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	gnome-dictionary
PORTVERSION=	3.6.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 dictionary lookup application

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc \
		itstool:${PORTSDIR}/textproc/itstool

CONFLICTS=	gnome-utils-2.[0-9]*

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack gtk30
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.dictionary.gschema.xml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdict-1.0.so.6

.include <bsd.port.mk>
