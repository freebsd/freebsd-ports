# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dconf
PORTVERSION=	0.24.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DISTNAME=	dconf-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Configuration database system for GNOME

BUILD_DEPENDS=	vala>=0.18.1:lang/vala \
		docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libdbus-1.so:devel/dbus

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		-e 's|"/etc"|"${PREFIX}/etc"|g' \
		${WRKSRC}/engine/dconf-engine.c \
		${WRKSRC}/engine/dconf-engine-profile.c \
		${WRKSRC}/engine/dconf-engine-source-system.c \
		${WRKSRC}/bin/dconf-update.c \
		${WRKSRC}/tests/engine.c
	@${REINPLACE_CMD} -e 's|-Wno-unused-but-set-variable||g' \
		${WRKSRC}/bin/Makefile.in \
		${WRKSRC}/client/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/docs/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dconf/db
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dconf/profile

.include <bsd.port.mk>
