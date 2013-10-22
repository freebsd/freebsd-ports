# Created by: Tobias Kortkamp <tobias.kortkamp@gmail.com>
# $FreeBSD$

PORTNAME=	easystroke
PORTVERSION=	0.6.0
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	tobias.kortkamp@gmail.com
COMMENT=	Easystroke is a gesture-recognition application for X11

LICENSE=	ISCL

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man \
		${LOCALBASE}/include/xorg/xserver-properties.h:${PORTSDIR}/x11-servers/xorg-server
LIB_DEPENDS=	gtkmm-3:${PORTSDIR}/x11-toolkits/gtkmm30 \
		dbus-glib:${PORTSDIR}/devel/dbus-glib \
		boost_serialization:${PORTSDIR}/devel/boost-libs

MAN1=		easystroke.1

USE_GCC=	any
USE_XORG=	x11 xtst
USES=		gettext gmake pkgconfig
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
BUILD_DEPENDS+=	intltool-merge:${PORTSDIR}/textproc/intltool
PLIST_SUB+=		NLS=""
ALL_TARGET=		easystroke.desktop all man
.else
# This builds easystroke without translations
ALL_TARGET=		man
PLIST_SUB+=		NLS="@comment "
# Create a .desktop file without translations.
# It's usually created by intltool-merge during the build.
pre-build:
	@${CP} ${WRKSRC}/${PORTNAME}.desktop.in ${WRKSRC}/${PORTNAME}.desktop
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.svg ${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MNLS}
	(cd ${WRKSRC}/po/ && \
		${COPYTREE_SHARE} \* ${PREFIX}/share/locale/ "-name *.mo")
.endif

.include <bsd.port.mk>
