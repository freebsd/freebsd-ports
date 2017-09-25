# Created by: arved
# $FreeBSD$

PORTNAME=	kdepimlibs
PORTVERSION=	${KDE4_KDEPIM_VERSION}
PORTREVISION=	12
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/${KDE4_APPLICATIONS_BRANCH}/applications/${KDE4_APPLICATIONS_VERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM Libraries

BUILD_DEPENDS=	xsltproc:textproc/libxslt
LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libsasl2.so:security/cyrus-sasl2 \
		libboost_thread.so:devel/boost-libs \
		libical.so:devel/libical \
		libuuid.so:misc/e2fsprogs-libuuid \
		libprison.so:graphics/prison \
		libqjson.so:devel/qjson

USES=		cmake:outsource kde:4 shared-mime-info shebangfix tar:xz
USE_KDE=	kdelibs akonadi \
		automoc4 ontologies soprano
SHEBANG_FILES=	mailtransport/kconf_update/migrate-transports.pl
USE_OPENLDAP=	yes
USE_QT4=	corelib dbus declarative designer_build gui network sql xml \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/modules/*.cmake
	${REINPLACE_CMD} -e 's|%%KDE_PREFIX%%|${KDE_PREFIX}|g' \
		${PATCH_WRKSRC}/cmake/modules/FindQGpgme.cmake
# Prevent updating MIME during build.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		${PATCH_WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
