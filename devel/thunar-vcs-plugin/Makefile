# Created by: Sergey V. Dyatko <sergey.dyatko@gmail.com>
# $FreeBSD$

PORTNAME=	thunar-vcs-plugin
PORTVERSION=	0.1.4
PORTREVISION=	13
CATEGORIES=	devel xfce
MASTER_SITES=	XFCE/src/thunar-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Version Control System plugin for Thunar

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 intltool intlhack
USE_XFCE=	thunar
INSTALLS_ICONS=	yes
USES=		pkgconfig gmake libtool gettext-tools xfce tar:bzip2

LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS GIT SVN
OPTIONS_DEFAULT=	SVN
GIT_DESC=	Git support
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
GIT_RUN_DEPENDS=	git:devel/git
GIT_CONFIGURE_ENABLE=	git
SVN_LIB_DEPENDS=	libsvn_client-1.so:devel/subversion
SVN_CONFIGURE_ENABLE=	subversion
OPTIONS_SUB=	yes

.include <bsd.port.mk>
