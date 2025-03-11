PORTNAME=	thunar-vcs-plugin
PORTVERSION=	0.3.0
CATEGORIES=	devel xfce
MASTER_SITES=	XFCE/thunar-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Version Control System plugin for Thunar
WWW=		https://docs.xfce.org/thunar-plugins/thunar-vcs-plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool localbase \
		pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf gtk30 glib20
USE_XFCE=	libexo thunar

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		GIT NLS SUBVERSION
OPTIONS_DEFAULT=	GIT
OPTIONS_SUB=		yes

GIT_RUN_DEPENDS=	git:devel/git
GIT_CONFIGURE_ENABLE=	git

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.if ${WITH_SUBVERSION_VER:U} == LTS
SUBVERSION_LIB_DEPENDS=	libsvn_client-1.so:devel/subversion-lts
.else
SUBVERSION_LIB_DEPENDS=	libsvn_client-1.so:devel/subversion
.endif
SUBVERSION_LIB_DEPENDS+=	libapr-1.so:devel/apr1
SUBVERSION_CONFIGURE_ENABLE=	subversion

.include <bsd.port.mk>
