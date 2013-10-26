# $FreeBSD$

PORTNAME=	kdeplasma-addons
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Extra plasmoids for KDE SC 4

LIB_DEPENDS=	qalculate.5:${PORTSDIR}/math/libqalculate \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
		qca.2:${PORTSDIR}/devel/qca \
		qoauth.1:${PORTSDIR}/net/qoauth \
		qjson.0:${PORTSDIR}/devel/qjson

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2

CONFLICTS_INSTALL=	plasma-applet-icontasks-0.[89].*

USE_XZ=		yes
USE_KDE4=	kdehier kdelibs kdeprefix libkexiv2 pimlibs workspace \
		akonadi attica automoc4 qimageblitz sharedmime soprano
USES=		cmake:outsource
USE_QT4=	corelib dbus declarative gui network script sql webkit \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11 xrender xtst
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MARBLE SCIM # IBUS
OPTIONS_DEFAULT=	MARBLE

MARBLE_DESC=	Support for desktop globe wallpaper
IBUS_DESC=	Enable IBUS backend for input dialog
SCIM_DESC=	Enable SCIM backend for input dialog

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMARBLE}
USE_KDE4+=	marble
PLIST_SUB+=	MARBLE=""
.else
CMAKE_ARGS+=	-DWITH_Marble:BOOL=FALSE
PLIST_SUB+=	MARBLE="@comment "
.endif

.if ${PORT_OPTIONS:MIBUS}
IGNORE=		requires ibus version 1.4.2 or greater
LIB_DEPENDS+=	ibus-1.0:${PORTSDIR}/textproc/ibus
PLIST_SUB+=	IBUS=""
.else
CMAKE_ARGS+=	-DBUILD_ibus=off
PLIST_SUB+=	IBUS="@comment "
.endif

.if ${PORT_OPTIONS:MSCIM}
LIB_DEPENDS+=	scim-1.0.10:${PORTSDIR}/textproc/scim
PLIST_SUB+=	SCIM=""
.else
CMAKE_ARGS+=	-DBUILD_scim=off
PLIST_SUB+=	SCIM="@comment "
.endif

post-patch:
	${GREP} -H -r "#include <q" ${WRKSRC} | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -f ${FILESDIR}/qt3to4headers.txt
	# Respect prefix, don't update MIME when installing.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${WRKSRC}/applets/lancelot/parts/CMakeLists.txt

.include <bsd.port.mk>
