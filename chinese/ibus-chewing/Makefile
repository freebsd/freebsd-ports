# Created by: Eric L. Camachat <eric@camachat.org>
# $FreeBSD$

PORTNAME=	ibus-chewing
PORTVERSION=	1.4.14
CATEGORIES=	chinese

MAINTAINER=	eric@camachat.org
COMMENT=	Chewing engine for IBus

LICENSE=	GPLv2

BUILD_DEPENDS=	gob2:devel/gob2 \
		${LOCALBASE}/share/cmake/Modules/ManageEnvironmentCommon.cmake:devel/cmake-fedora \
		ibus-daemon:textproc/ibus
LIB_DEPENDS=	libchewing.so:chinese/libchewing
RUN_DEPENDS=	ibus-daemon:textproc/ibus

CMAKE_ARGS=	-DSYSCONF_INSTALL_DIR=${PREFIX}/etc \
		-DLIB_DIR=${PREFIX}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.freedesktop.IBus.Chewing.gschema.xml
USES=		cmake gettext pkgconfig
USE_GNOME=	gtk20
USE_XORG=	xtst

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	definite

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${CHEWING_DATADIR}|$${CHEWING_chewing_DATADIR}|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|/usr|${PREFIX}|' \
		${WRKSRC}/data/ibus-setup-chewing.desktop

.include <bsd.port.mk>
