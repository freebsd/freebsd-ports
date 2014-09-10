# Created by: miwi
# $FreeBSD$

PORTNAME=	kdepim-runtime
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libkgapi2.so:${PORTSDIR}/devel/libkgapi \
		libkolab.so:${PORTSDIR}/devel/libkolab \
		libkfbapi.so:${PORTSDIR}/net/libkfbapi

CONFLICTS_INSTALL=	kdepim-runtime44-4.*

USE_GNOME=	libxml2 libxslt:build
USE_KDE4=	kdehier kdelibs kdeprefix pimlibs nepomuk-core \
		akonadi automoc4 ontologies soprano strigi
USES=		cmake:outsource shared-mime-info tar:xz
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
