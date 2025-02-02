PORTNAME=	khangman
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Hangman game for KDE 4
WWW=		https://edu.kde.org/khangman

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		crash doctools i18n kdeclarative libkeduvocdocument newstuff \
		notifications package service widgetsaddons xmlgui \
		ecm:build
USE_QT=		base declarative
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
