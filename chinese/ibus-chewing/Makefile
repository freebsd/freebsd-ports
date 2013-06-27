# Created by: Eric L. Camachat <eric@camachat.org>
# $FreeBSD$

PORTNAME=	ibus-chewing
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	eric@camachat.org
COMMENT=	Chewing engine for IBus

LICENSE=	GPLv2

BUILD_DEPENDS=	gob2:${PORTSDIR}/devel/gob2 \
		${LOCALBASE}/share/cmake/Modules/ManageEnvironment.cmake:${PORTSDIR}/devel/cmake-fedora \
		ibus-daemon:${PORTSDIR}/textproc/ibus
RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus
LIB_DEPENDS=	chewing:${PORTSDIR}/chinese/libchewing

CMAKE_ARGS+=	-DSYSCONF_INSTALL_DIR=${PREFIX}/etc \
		-DLIB_DIR=${PREFIX}/lib
GCONF_SCHEMAS=	${PORTNAME}.schemas
USES=		cmake gettext
USE_GNOME=	gconf2 gtk20
USE_XORG=	xtst

PROJECTHOST=	ibus

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
