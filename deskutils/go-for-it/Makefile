PORTNAME=	go-for-it
DISTVERSION=	1.9.2
CATEGORIES=	deskutils

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Stylish to-do list with built-in productivity timer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libnotify.so:devel/libnotify

USES=		cmake compiler:c11 gettext gnome pkgconfig
CMAKE_ARGS=	-DAPP_SYSTEM_NAME:STRING=${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	JMoerman
GH_PROJECT=	Go-For-It
USE_GNOME=	cairo glib20 gtk30 intltool
GLIB_SCHEMAS=	com.github.jmoerman.go-for-it.gschema.xml
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
