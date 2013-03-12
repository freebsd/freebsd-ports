# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/dconf/Makefile,v 1.30 2012/10/03 17:57:17 kwm Exp $

PORTNAME?=	dconf
PORTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DISTNAME=	dconf-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A configuration database system for GNOME

BUILD_DEPENDS=	vala>=0.15.1:${PORTSDIR}/lang/vala
LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gnomehier
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DCONF_SLAVE?=	no

.if ${DCONF_SLAVE} == "editor"
USE_GNOME+=	gtk30
INSTALLS_ICONS=	yes
GLIB_SCHEMAS=	ca.desrt.dconf-editor.gschema.xml
LIB_DEPENDS+=	dconf:${PORTSDIR}/devel/dconf
.else
CONFIGURE_ARGS+=--disable-editor
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/engine/dconf-engine.c \
		${WRKSRC}/bin/dconf-update.c
	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' \
		${WRKSRC}/editor/dconf-model.c
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/editor/dconf-model.vala
	@${REINPLACE_CMD} -e 's|-Wno-unused-but-set-variable||g' \
		${WRKSRC}/bin/Makefile.in \
		${WRKSRC}/client/Makefile.in \
		${WRKSRC}/editor/Makefile.in

pre-build:
#	${GMAKE} -C ${WRKSRC}/client dconf-client.c libdconf.so.0
#	${GMAKE} -C ${WRKSRC}/dbus-1 dconf-dbus-1.c libdconf-dbus-1.so.0

post-install:
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/gio/modules
	@${MKDIR} ${PREFIX}/etc/dconf/db
	@${MKDIR} ${PREFIX}/etc/dconf/profile

.include <bsd.port.mk>
