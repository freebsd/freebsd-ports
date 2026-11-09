PORTNAME=	kdepim
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM applications metaport
WWW=		https://www.kde.org/

RUN_DEPENDS=	akonadi-calendar-tools>=0:deskutils/akonadi-calendar-tools \
		pim-sieve-editor>=0:deskutils/pim-sieve-editor

USES=		kde:6 metaport qt:6
USE_KDE=	${_USE_KDEPIM_ALL}

.include <bsd.port.mk>
