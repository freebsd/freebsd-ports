PORTNAME=	akregator
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Feed reader for KDE
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp

USES=		cmake desktop-file-utils gettext-tools kde:6 qt:6 \
		tar:xz
# KDE Frameworks
USE_KDE=	codecs crash i18n iconthemes kcmutils ktextaddons \
		notifications notifyconfig parts statusnotifieritem \
		syndication userfeedback xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	grantleetheme kontactinterface libkdepim messagelib \
		pimcommon
# KDE Plasma
USE_KDE+=	activities
USE_QT=		base declarative webengine
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
