PORTNAME=	ibus-chewing
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.7
CATEGORIES=	chinese

MAINTAINER=	eric@camachat.org
COMMENT=	Chewing engine for IBus
WWW=		https://github.com/chewing/ibus-chewing

LICENSE=	GPLv2

BUILD_DEPENDS=	ibus-daemon:textproc/ibus
LIB_DEPENDS=	libchewing.so:chinese/libchewing
RUN_DEPENDS=	ibus-daemon:textproc/ibus

CMAKE_ARGS=	-DSYSCONF_INSTALL_DIR=${PREFIX}/etc \
		-DLIB_DIR=${PREFIX}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.freedesktop.IBus.Chewing.gschema.xml
USES=		cmake:noninja gettext gnome pkgconfig xorg
USE_GNOME=	glib20 gtk40 libadwaita
USE_XORG=	xtst

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	chewing

.include <bsd.port.mk>
