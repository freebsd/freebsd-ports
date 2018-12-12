# $FreeBSD$

PORTNAME=	grantlee-editor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Editor for Grantlee themes

LICENSE=	LGPL21

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake:outsource compiler:c++11-lib gettext grantlee:5 \
		kde:5 qt:5 tar:xz
USE_KDE=	archive attica auth codecs completion config configwidgets \
		coreaddons crash dbusaddons  ecm i18n itemmodels jobwidgets \
		kio newstuff service syntaxhighlighting texteditor \
		widgetsaddons xmlgui
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime contacts grantleetheme \
		kdepim-apps-libs libkleo messagelib mime pimcommon pimtextedit
USE_QT=		core dbus declarative gui location network webchannel webengine \
		widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr


OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
