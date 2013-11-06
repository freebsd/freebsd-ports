# Created by: Golyashov Sergei <svvord@mail.ru>
# $FreeBSD$

PORTNAME=	kdevelop
DISTVERSION=	${KDEVELOP_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${DISTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugin extensible IDE for KDE

LIB_DEPENDS=	kdevplatforminterfaces:${PORTSDIR}/devel/kdevplatform
RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake

LATEST_LINK=	${PORTNAME}-kde4

USE_KDE4=	kdehier kdelibs kdeprefix sharedmime workspace automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build
USE_XZ=		yes
USES=		cmake gmake shared-mime-info

OPTIONS_DEFINE=	OKTETA PHP NLS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

OKTETA_DESC=	Hex editing support via Okteta

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOKTETA}
LIB_DEPENDS+=	okteta1core:${PORTSDIR}/devel/kdesdk4
PLIST_SUB+=	OKTETA=""
.else
CMAKE_ARGS+=	-DWITH_LibOkteta:BOOL=FALSE
PLIST_SUB+=	OKTETA="@comment "
.endif

.if ${PORT_OPTIONS:MPHP}
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/kdevphplanguagesupport.so:${PORTSDIR}/devel/kdevelop-php
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DBUILD_po:BOOL=FALSE
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/app/CMakeLists.txt

.include <bsd.port.mk>
