# Created by: Tobias Kortkamp <tobias.kortkamp@gmail.com>
# $FreeBSD$

PORTNAME=	easystroke
PORTVERSION=	0.6.0
PORTREVISION=	21
CATEGORIES=	deskutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easystroke is a gesture-recognition application for X11

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_11_powerpc64=	fails to build on powerpc64 elfv1: handler.cc:560:27: call of overloaded 'abs(float&)' is ambiguous
BROKEN_FreeBSD_12_powerpc64=	fails to build on powerpc64 elfv1: handler.cc:560:27: call of overloaded 'abs(float&)' is ambiguous

BUILD_DEPENDS=	help2man:misc/help2man \
		${LOCALBASE}/include/xorg/xserver-properties.h:x11-servers/xorg-server
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libboost_serialization.so:devel/boost-libs

USES=		compiler:c++11-lang gettext gmake gnome pkgconfig xorg
USE_GNOME=	gtkmm30
USE_XORG=	x11 xext xfixes xi xtst
USE_CXXSTD=	c++11
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_BUILD_DEPENDS=	intltool-merge:textproc/intltool
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
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.svg ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-NLS-on:
	(cd ${WRKSRC}/po/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/locale/ "-name *.mo")

.include <bsd.port.mk>
