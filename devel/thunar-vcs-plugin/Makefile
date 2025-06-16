PORTNAME=	thunar-vcs-plugin
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel xfce
MASTER_SITES=	XFCE/thunar-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Version Control System plugin for Thunar
WWW=		https://docs.xfce.org/thunar-plugins/thunar-vcs-plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext-tools gnome localbase:ldflags meson \
		pkgconfig tar:xz xfce
USE_GNOME=	glib20 gtk30
USE_XFCE=	libexo thunar

OPTIONS_DEFINE=		GIT NLS SUBVERSION
OPTIONS_DEFAULT=	GIT
OPTIONS_SUB=		yes

GIT_RUN_DEPENDS=	git:devel/git
GIT_MESON_ENABLED=	git

NLS_USES=		gettext-runtime

.if ${WITH_SUBVERSION_VER:U} == LTS
SUBVERSION_LIB_DEPENDS=		libsvn_client-1.so:devel/subversion-lts
.else
SUBVERSION_LIB_DEPENDS=		libsvn_client-1.so:devel/subversion
.endif
SUBVERSION_LIB_DEPENDS+=	libapr-1.so:devel/apr1
SUBVERSION_MESON_ENABLED=	svn

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
