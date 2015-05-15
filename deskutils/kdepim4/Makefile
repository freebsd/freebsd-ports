# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdepim
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM applications

LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme \
		libassuan.so:${PORTSDIR}/security/libassuan \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2 \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libgrantlee_gui.so:${PORTSDIR}/devel/grantlee \
		libkgapi2.so:${PORTSDIR}/devel/libkgapi
RUN_DEPENDS=	${KDE4_PREFIX}/bin/accountwizard:${PORTSDIR}/deskutils/kdepim4-runtime \
		${LOCALBASE}/bin/gmd5sum:${PORTSDIR}/sysutils/coreutils

CONFLICTS_INSTALL=	kdepim44-4.*

USE_GNOME=	libxml2 libxslt:build
USE_KDE4=	kdelibs kdeprefix pimlibs kactivities \
		akonadi automoc4 soprano nepomuk-widgets baloo
USES=		cmake:outsource gmake iconv tar:xz
USE_OPENLDAP=	yes
USE_QT4=	corelib dbus declarative designer_build gui network opengl \
		qt3support script sql webkit xml \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11 xscrnsaver
CMAKE_ARGS+=	-DKDEPIM_BUILD_MOBILE:BOOL=FALSE
# Avoids Clang error:
# https://git.reviewboard.kde.org/r/108617
CXXFLAGS+=	-Wno-error=return-type
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

PLIST_SUB=	GRANTLEE_VER=0.5

post-patch:
# Remove BOM
	${REINPLACE_CMD} -e '1 s|^.*/|/|g' \
		${WRKSRC}/knotes/configdialog/knotecollectionconfigwidget.cpp

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kleo
	${INSTALL_DATA} ${WRKSRC}/libkleo/kleo/*.h \
		${STAGEDIR}${PREFIX}/include/kleo
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kleo/ui
	${INSTALL_DATA} ${WRKSRC}/libkleo/ui/*.h \
		${STAGEDIR}${PREFIX}/include/kleo/ui

.include <bsd.port.mk>
