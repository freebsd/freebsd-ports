PORTNAME=	khangman
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Hangman game for KDE
WWW=		https://apps.kde.org/khangman/

RUN_DEPENDS=	kdeedu-data>=${KDE_APPLICATIONS_VERSION}:misc/kdeedu-data

USES=		cmake compiler:c++17-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	completion config coreaddons crash i18n kio \
		libkeduvocdocument newstuff notifications \
		ecm:build
USE_QT=		base declarative
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
