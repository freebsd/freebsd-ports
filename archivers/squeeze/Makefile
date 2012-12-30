# Created by: markand
# $FreeBSD$

PORTNAME=	squeeze
PORTVERSION=	0.2.3
PORTREVISION=	6
CATEGORIES=	archivers xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Squeeze is a modern and advanced archive manager

LICENSE=	GPLv2

LIB_DEPENDS=	thunar-vfs-1:${PORTSDIR}/x11-fm/thunar-vfs

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

USE_XFCE=	configenv libutil thunar
USE_XORG=	x11
USE_GNOME=	gnomehack gtk20 glib20 intltool intlhack desktopfileutils
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
MAKE_JOB_SAFE=	yes
USE_PKGCONFIG=	build

OPTIONS_DEFINE=		DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB=	GTKDOC=""
.else
PLIST_SUB=	GTKDOC="@comment "
.endif

post-patch:
# Needed to remove gtk-doc installation
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e "s|docs||g" ${WRKSRC}/Makefile.in
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
