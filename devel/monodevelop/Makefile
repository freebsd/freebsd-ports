# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	monodevelop
PORTVERSION=	5.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/
DISTFILES=	${DISTNAME}-0${EXTRACT_SUFX}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	IDE for the .NET platform

BUILD_DEPENDS=	mautil:devel/mono-addins
RUN_DEPENDS=	${LOCALBASE}/lib/libgdiplus.a:x11-toolkits/libgdiplus \
		exctags:devel/ctags \
		mautil:devel/mono-addins

BROKEN=		GUI does not start
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-04-15

USE_GNOME=	gtksharp20 gnomesharp20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-mimedb --disable-update-desktopdb
CONFIGURE_ENV=	ac_cv_path_MCS=${LOCALBASE}/bin/mcs
USES=		desktop-file-utils gettext gmake mono pathfix shared-mime-info tar:bzip2
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	MONOEXT GIT SVN
OPTIONS_DEFAULT=MONOEXT GIT SVN
MONOEXT_DESC=	Extensions for Mono development
GIT_DESC=	git support

MONOEXT_CONFIGURE_ENABLE=monoextensions
GIT_CONFIGURE_ENABLE=git
GIT_RUN_DEPENDS=git:devel/git
SVN_CONFIGURE_ENABLE=subversion
SVN_RUN_DEPENDS=svn:devel/subversion

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

post-patch:
	@${REINPLACE_CMD} -e 's|[(]gnome_data[)]/mime$$|(prefix)/share/mime|g ; \
		s|[(]gnome_data[)]/mime/packages$$|(prefix)/share/mime/packages|g ; \
		s|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/monodevelop.in \
		${WRKSRC}/mdtool.in

.include <bsd.port.mk>
