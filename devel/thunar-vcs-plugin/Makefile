PORTNAME=	thunar-vcs-plugin
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	devel xfce
MASTER_SITES=	XFCE/thunar-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Version Control System plugin for Thunar

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext-tools gmake gnome libtool localbase \
		pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gtk30 glib20 intltool
USE_XFCE=	libexo thunar

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		GIT NLS SUBVERSION
OPTIONS_DEFAULT=	SUBVERSION
OPTIONS_SUB=		yes

GIT_CONFIGURE_ENABLE=	git
GIT_RUN_DEPENDS=	git:devel/git

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

SUBVERSION_CONFIGURE_ENABLE=	subversion
SUBVERSION_LIB_DEPENDS=		libsvn_client-1.so:devel/subversion \
				libapr-1.so:devel/apr1

.include <bsd.port.mk>
