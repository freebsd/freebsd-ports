# Created by: miwi
# $FreeBSD$

PORTNAME=	kdepim-runtime
PORTVERSION=	${KDE4_KDELIBS_VERSION}
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/${KDE4_APPLICATIONS_BRANCH}/applications/${KDE4_APPLICATIONS_VERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM tools and services

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libkgapi2.so:devel/libkgapi \
		libkolab.so:devel/libkolab \
		libkolabxml.so:textproc/libkolabxml \
		libkfbapi.so:net/libkfbapi \
		libqjson.so:devel/qjson

CONFLICTS_INSTALL=	kdepim-runtime44-4.*

USES=		cmake:outsource kde:4 shared-mime-info tar:xz
USE_GNOME=	libxml2 libxslt:build
USE_KDE=	kdelibs pimlibs \
		akonadi automoc4
USE_QT4=	corelib dbus declarative designer_build gui network qtestlib \
		script xml xmlpatterns \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null
CMAKE_ARGS=	-DKDEPIM_MOBILE_UI:BOOL=OFF

post-patch:
# Prevent updating MIME during build.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		${PATCH_WRKSRC}/CMakeLists.txt \
		${PATCH_WRKSRC}/accountwizard/CMakeLists.txt \
		${PATCH_WRKSRC}/resources/facebook/serializer/CMakeLists.txt

.include <bsd.port.mk>
