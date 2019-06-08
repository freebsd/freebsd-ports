# Created by: Sergey V. Dyatko <sergey.dyatko@gmail.com>
# $FreeBSD$

PORTNAME=	thunar-vcs-plugin
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	devel xfce
MASTER_SITES=	XFCE/src/thunar-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Version Control System plugin for Thunar

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libapr-1.so:devel/apr1

USES=		gettext-tools gmake libtool localbase pkgconfig tar:bzip2 \
		xfce
USE_GNOME=	cairo glib20 gtk20 intlhack intltool
USE_XFCE=	libexo thunar

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS GIT SVN
OPTIONS_DEFAULT=	SVN
OPTIONS_SUB=		yes

GIT_DESC=		Git support

GIT_CONFIGURE_ENABLE=	git
GIT_RUN_DEPENDS=	git:devel/git

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

SVN_CONFIGURE_ENABLE=	subversion
SVN_LIB_DEPENDS=	libsvn_client-1.so:devel/subversion

.include <bsd.port.mk>
