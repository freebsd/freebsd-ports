# Created by: arved
# $FreeBSD$

PORTNAME=	kdepimlibs
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme \
		sasl2:${PORTSDIR}/security/cyrus-sasl2 \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		ical:${PORTSDIR}/devel/libical \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		prison:${PORTSDIR}/graphics/prison

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_XZ=	yes
USE_KDE4=	kdelibs akonadi kdeprefix kdehier \
		automoc4 ontologies sharedmime soprano
KDE4_BUILDENV=	yes
USE_OPENLDAP=	yes
USE_QT4=	dbus designer gui network sql xml \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

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
