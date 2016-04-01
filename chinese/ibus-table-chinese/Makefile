# $FreeBSD$

PORTNAME=	ibus-table-chinese
PORTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	ibus
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	dennylin93@hs.ntnu.edu.tw
COMMENT=	Chinese input tables for IBus

BUILD_DEPENDS=	${LOCALBASE}/share/cmake/Modules/ManageEnvironment.cmake:devel/cmake-fedora \
		ibus-daemon:textproc/ibus \
		${LOCALBASE}/libexec/ibus-engine-table:textproc/ibus-table
RUN_DEPENDS=	ibus-daemon:textproc/ibus \
		${LOCALBASE}/libexec/ibus-engine-table:textproc/ibus-table

USES=		cmake pkgconfig
INSTALL_TARGET=	install
DATADIR=	${PREFIX}/share/ibus-table
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
