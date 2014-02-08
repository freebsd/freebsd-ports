# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/glade/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	glade
PORTVERSION=	3.12.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	User interface builder for GTK+ 3

CONFLICTS=	glade3-3.*

INSTALLS_ICONS=	yes
USE_XZ=		yes
USE_GNOME=	gtk30 gnomeprefix gnomedocutils introspection:build
USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/gladeui-2

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
USE_GNOME+=	pygobject3
PLIST_SUB+=	PYTHON:=""
CONFIGURE_ARGS+=--enable-python
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON:="@comment "
.endif

#post-install:
#	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgladeui-2.so.2
#	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/glade/modules/lib*.so

.include <bsd.port.mk>
