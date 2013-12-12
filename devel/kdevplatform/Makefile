# Created by: Golyashov Sergei <svvord@mail.ru>
# $FreeBSD$

PORTNAME=	kdevplatform
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Set of libraries for KDE IDE-like programs

LIB_DEPENDS=	libsvn_client-1.so:${PORTSDIR}/devel/subversion \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libqjson.so:${PORTSDIR}/devel/qjson \
		libgrantlee_gui.so:${PORTSDIR}/devel/grantlee

USE_KDE4=	kate_run kdehier kdelibs kdeprefix automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build \
		corelib designer_build gui webkit
USE_XZ=		yes
USES=		cmake
USE_LDCONFIG=	yes

PLIST_SUB+=	SHLIB_VER=7.0.0 \
		SHLIB_SHVER=7

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DBUILD_po:BOOL=Off
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
