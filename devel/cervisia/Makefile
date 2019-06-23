# $FreeBSD$

PORTNAME=	cervisia
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	CVS Frontend for KDE

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 \
		qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons doctools ecm i18n iconthemes init itemviews \
		jobwidgets kdesu kio notifications parts pty service sonnet \
		textwidgets widgetsaddons xmlgui
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
