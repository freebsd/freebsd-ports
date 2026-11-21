PORTNAME=	easystroke
DISTVERSION=	0.6.0-9
DISTVERSIONSUFFIX=	-gf7c1614
PORTREVISION=	14
CATEGORIES=	deskutils

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Gesture-recognition application for X11
WWW=		https://github.com/thjaeger/easystroke

LICENSE=	ISC
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/xorg/xserver-properties.h:x11-servers/xorg-server \
		help2man:misc/help2man
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib

USES=		compiler:c++11-lang gettext-tools gmake gnome pkgconfig xorg
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	thjaeger
USE_GNOME=	gtkmm30 intltool
USE_XORG=	x11 xext xfixes xi xtst

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_ALL_TARGET=		easystroke.desktop all man
# This builds easystroke without translations
NLS_ALL_TARGET_OFF=	man

# Create a .desktop file without translations.
# It's usually created by intltool-merge during the build.
pre-build-NLS-off:
	@${CP} ${WRKSRC}/${PORTNAME}.desktop.in ${WRKSRC}/${PORTNAME}.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.appdata.xml ${STAGEDIR}${PREFIX}/share/metainfo/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.svg ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-NLS-on:
	(cd ${WRKSRC}/po/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/locale/ "-name *.mo")

.include <bsd.port.mk>
