# New ports collection makefile for:	kdeplasmoids
# Date created:		2008-06-29
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kdeplasma-addons
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Extra plasmoids for KDE4

LIB_DEPENDS=	qalculate.5:${PORTSDIR}/math/libqalculate \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
		qca.2:${PORTSDIR}/devel/qca

BUILD_DEPENDS=	eigen>=2.0.b3:${PORTSDIR}/math/eigen2

CONFLICTS_INSTALL=	plasma-applet-icontasks-0.[89].*

USE_XZ=	yes
USE_KDE4=	kdehier kdelibs kdeprefix libkexiv2 pimlibs workspace \
		akonadi attica automoc4 qimageblitz sharedmime soprano
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui network opengl script sql svg webkit xml \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11 xrender xtst
MAKE_JOBS_SAFE=	yes

OPTIONS=	MARBLE "Support for desktop globe wallpaper" on \
		IBUS "Enable IBUS backend for input dialog" off \
		SCIM "Enable SCIM backend for input dialog" off

.include <bsd.port.options.mk>

.ifndef(WITHOUT_MARBLE)
USE_KDE4+=	marble
PLIST_SUB+=	MARBLE=""
.else
CMAKE_ARGS+=	-DWITH_Marble:BOOL=FALSE
PLIST_SUB+=	MARBLE="@comment "
.endif

.ifdef(WITH_IBUS)
LIB_DEPENDS+=	ibus-1.0:${PORTSDIR}/textproc/ibus
PLIST_SUB+=	IBUS=""
.else
CMAKE_ARGS+=	-DWITH_IBUS:BOOL=FALSE
PLIST_SUB+=	IBUS="@comment "
.endif

.ifdef(WITH_SCIM)
LIB_DEPENDS+=	scim-1.0.10:${PORTSDIR}/textproc/scim
PLIST_SUB+=	SCIM=""
.else
CMAKE_ARGS+=	-DWITH_SCIM:BOOL=FALSE
PLIST_SUB+=	SCIM="@comment "
.endif

post-patch:
	${GREP} -H -r "#include <q" ${WRKSRC} | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -f ${FILESDIR}/qt3to4headers.txt
	# Respect prefix, don't update MIME when installing.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${WRKSRC}/applets/lancelot/parts/CMakeLists.txt

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
