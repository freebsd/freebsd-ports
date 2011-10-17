# New ports collection Makefile for:	kdepimplibs
# Date created:				2008-01-20
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kdepimlibs
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

LIB_DEPENDS=	gpgme.19:${PORTSDIR}/security/gpgme \
		sasl2.2:${PORTSDIR}/security/cyrus-sasl2 \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		ical.44:${PORTSDIR}/devel/libical \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		prison.0:${PORTSDIR}/graphics/prison \
		soprano.4:${PORTSDIR}/textproc/soprano

BUILD_DEPENDS=	${LOCALBASE}/share/ontology/core/rdf.ontology:${PORTSDIR}/x11-toolkits/shared-desktop-ontologies \
		xsltproc:${PORTSDIR}/textproc/libxslt

RUN_DEPENDS=	${LOCALBASE}/share/ontology/core/rdf.ontology:${PORTSDIR}/x11-toolkits/shared-desktop-ontologies

USE_BZIP2=	yes
USE_KDE4=	kdelibs akonadi kdeprefix kdehier automoc4 sharedmime
KDE4_BUILDENV=	yes
USE_OPENLDAP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus designer gui network sql xml \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.if exists(${LOCALBASE}/lib/libgpgme-pth.so)
PLIST_SUB+=	WITH_PTH=''
.else
PLIST_SUB+=	WITH_PTH='@comment '
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/modules/*.cmake
	${REINPLACE_CMD} -e '/find_package/s,PATHS,PATHS ${KDE4_PREFIX}/lib/cmake/Akonadi,' \
		${PATCH_WRKSRC}/cmake/modules/FindAkonadi.cmake
	${REINPLACE_CMD} -e 's|%%KDE4_PREFIX%%|${KDE4_PREFIX}|g' \
		${PATCH_WRKSRC}/cmake/modules/FindQGpgme.cmake
	# Prevent updating MIME during build.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		${PATCH_WRKSRC}/CMakeLists.txt

post-install:
	@-update-mime-database ${KDE4_PREFIX}/share/mime

.include <bsd.port.mk>
