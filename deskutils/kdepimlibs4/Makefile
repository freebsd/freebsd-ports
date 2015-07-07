# Created by: arved
# $FreeBSD$

PORTNAME=	kdepimlibs
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM Libraries

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2 \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libical.so:${PORTSDIR}/devel/libical \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libprison.so:${PORTSDIR}/graphics/prison \
		libqjson.so:${PORTSDIR}/devel/qjson

USE_KDE4=	kdelibs akonadi kdeprefix \
		automoc4 ontologies soprano
USES=		cmake:outsource shared-mime-info shebangfix tar:xz
SHEBANG_FILES=	mailtransport/kconf_update/migrate-transports.pl
USE_OPENLDAP=	yes
USE_QT4=	corelib dbus declarative designer_build gui network sql xml \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/modules/*.cmake
	${REINPLACE_CMD} -e 's|%%KDE4_PREFIX%%|${KDE4_PREFIX}|g' \
		${PATCH_WRKSRC}/cmake/modules/FindQGpgme.cmake
# Prevent updating MIME during build.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		${PATCH_WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
