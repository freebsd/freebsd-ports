# Created by: Sergey V. Dyatko <sergey.dyatko@gmail.com>
# $FreeBSD$

PORTNAME=	thunar-vcs-plugin
PORTVERSION=	0.1.4
PORTREVISION=	10
CATEGORIES=	devel xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/thunar-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Version Control System plugin for Thunar

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 intltool intlhack
USE_XFCE=	configenv libexo libutil thunar
INSTALLS_ICONS=	yes
USES=		pkgconfig gmake

LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS GIT SVN
OPTIONS_DEFAULT=	SVN
GIT_DESC=	Git support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGIT}
RUN_DEPENDS+=	git:${PORTSDIR}/devel/git
CONFIGURE_ARGS+=--enable-git
PLIST_SUB+=	GIT=""
.else
CONFIGURE_ARGS+=--disable-git
PLIST_SUB+=	GIT="@comment "
.endif

.if ${PORT_OPTIONS:MSVN}
LIB_DEPENDS+=	libsvn_client-1.so:${PORTSDIR}/devel/subversion
CONFIGURE_ARGS+=--enable-subversion
PLIST_SUB+=	SVN=""
.else
CONFIGURE_ARGS+=--disable-subversion
PLIST_SUB+=	SVN="@comment "
.endif

.include <bsd.port.mk>
