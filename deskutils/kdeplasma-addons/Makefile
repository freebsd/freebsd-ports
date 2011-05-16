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

BUILD_DEPENDS=	eigen>=2.0.b3:${PORTSDIR}/math/eigen2
LIB_DEPENDS=	kexiv2:${PORTSDIR}/graphics/kdegraphics4 \
		qalculate.5:${PORTSDIR}/math/libqalculate \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
		marblewidget.11:${PORTSDIR}/astro/marble

USE_KDE4=	kdelibs pimlibs workspace kdeprefix kdehier automoc4 sharedmime
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus qt3support webkit \
		designer network svg qtestlib xml \
		qmake_build moc_build rcc_build uic_build

MAKE_JOBS_SAFE=	yes

OPTIONS=	SCIM "Enable SCIM method input dialog" off

.include <bsd.port.options.mk>

.if defined(WITHOUT_SCIM)
PLIST_SUB+=	SCIM="@comment "
.else
LIB_DEPENDS+=	scim-1.0.10:${PORTSDIR}/textproc/scim
PLIST_SUB+=	SCIM=""
.endif

post-patch:
	${GREP} -H -r "#include <q" ${WRKSRC} | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -f ${FILESDIR}/qt3to4headers.txt

.if defined(WITHOUT_SCIM)
	${REINPLACE_CMD} -e '/add_subdirectory(kimpanel)/d' \
		${WRKSRC}/applets/CMakeLists.txt
.endif
	#respect prefix, don't update mime when installing
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
		${WRKSRC}/applets/lancelot/parts/CMakeLists.txt

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
