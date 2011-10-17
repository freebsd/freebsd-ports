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

LIB_DEPENDS=	kexiv2.10:${PORTSDIR}/graphics/libkexiv2-kde4 \
		qalculate.5:${PORTSDIR}/math/libqalculate \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
		soprano.4:${PORTSDIR}/textproc/soprano \
		attica.0:${PORTSDIR}/x11-toolkits/attica \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		qca.2:${PORTSDIR}/devel/qca

BUILD_DEPENDS=	eigen>=2.0.b3:${PORTSDIR}/math/eigen2

USE_BZIP2=	yes
USE_KDE4=	kdehier kdelibs kdeprefix pimlibs workspace \
		akonadi sharedmime automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui network opengl script sql svg webkit xml \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11 xrender xtst
MAKE_JOBS_SAFE=	yes

OPTIONS=	MARBLE "Support for desktop globe wallpaper" on \
		SCIM "Enable SCIM method input dialog" off

.include <bsd.port.options.mk>

.ifndef(WITHOUT_MARBLE)
LIB_DEPENDS+=	marblewidget.12:${PORTSDIR}/astro/marble
PLIST_SUB+=	MARBLE=""
.else
CMAKE_ARGS+=	-DWITH_Marble:BOOL=FALSE
PLIST_SUB+=	MARBLE="@comment "
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
