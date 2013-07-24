# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	monodevelop
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	IDE for the .NET platform

BUILD_DEPENDS=	mautil:${PORTSDIR}/devel/mono-addins \
		update-desktop-database:${PORTSDIR}/devel/desktop-file-utils
RUN_DEPENDS=	${LOCALBASE}/lib/libgdiplus.a:${PORTSDIR}/x11-toolkits/libgdiplus \
		exctags:${PORTSDIR}/devel/ctags \
		mautil:${PORTSDIR}/devel/mono-addins

USE_GNOME=	gnomehack gtksharp20 gnomesharp20
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
MAN1=		mdtool.1 monodevelop.1
USES=		gettext gmake
INSTALLS_ICONS=	yes

BROKEN=		Does not build with recent mono

OPTIONS_DEFINE=	MONOEXT GIT SVN
OPTIONS_DEFAULT=	MONOEXT GIT SVN
MONOEXT_DESC=	Extensions for Mono development
GIT_DESC=	git support

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMONOEXT}
CONFIGURE_ARGS+=--enable-monoextensions
PLIST_SUB+=	MONOEXT=""
.else
CONFIGURE_ARGS+=--disable-monoextensions
PLIST_SUB+=	MONOEXT="@comment "
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
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
CONFIGURE_ARGS+=--enable-subversion
PLIST_SUB+=	SVN=""
.else
CONFIGURE_ARGS+=--disable-subversion
PLIST_SUB+=	SVN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]gnome_data[)]/mime$$|(prefix)/share/mime|g ; \
		s|[(]gnome_data[)]/mime/packages$$|(prefix)/share/mime/packages|g ; \
		s|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/monodevelop.in \
		${WRKSRC}/mdtool.in

post-install:
	@-update-desktop-database

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
