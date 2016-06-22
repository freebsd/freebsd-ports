# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdepim
PORTVERSION=	${KDE4_KDELIBS_VERSION}
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/${KDE4_APPLICATIONS_BRANCH}/applications/${KDE4_APPLICATIONS_VERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM applications

LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libassuan.so:security/libassuan \
		libsasl2.so:security/cyrus-sasl2 \
		libboost_thread.so:devel/boost-libs \
		libgrantlee_gui.so:devel/grantlee \
		libkgapi2.so:devel/libkgapi
RUN_DEPENDS=	${KDE4_PREFIX}/bin/accountwizard:deskutils/kdepim4-runtime \
		${LOCALBASE}/bin/gmd5sum:sysutils/coreutils

CONFLICTS_INSTALL=	kdepim44-4.*

USE_GNOME=	libxml2 libxslt:build
USE_KDE4=	kdelibs pimlibs kactivities \
		akonadi automoc4 soprano nepomuk-widgets baloo
USES=		cmake:outsource gmake iconv shebangfix tar:xz
SHEBANG_FILES=	agents/mailfilteragent/kconf_update/migrate-kmail-filters.pl \
		kalarm/*.pl kmail/kconf_update/*.pl \
		libkpgp/kconf_update/kpgp-3.1-upgrade-address-data.pl
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

# net-im/kopete-kde4 needs Kleopatra's headers for its Cryptography plugin.
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kde4/kleo
	${INSTALL_DATA} ${WRKSRC}/libkleo/kleo/*.h \
		${STAGEDIR}${PREFIX}/include/kde4/kleo
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kde4/kleo/ui
	${INSTALL_DATA} ${WRKSRC}/libkleo/ui/*.h \
		${STAGEDIR}${PREFIX}/include/kde4/kleo/ui

.include <bsd.port.mk>
