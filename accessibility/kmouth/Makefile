PORTNAME=	kmouth
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	accessibility kde kde-applications
PATCH_SITES=	https://invent.kde.org/accessibility/kmouth/-/commit/
PATCHFILES=	cfb889ab38befe1e378d92ab9915aed14ec5843b.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Speech synthesizer frontend for KDE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		i18n jobwidgets kio service solid widgetsaddons windowsystem xmlgui \
		ecm_build
USE_QT=		concurrent core dbus gui network printsupport speech widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
