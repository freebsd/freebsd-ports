PORTNAME=	libkcompactdisc
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for interfacing with audio CDs
WWW=		https://www.kde.org/

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	coreaddons i18n itemmodels itemviews phonon solid \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ALSA DOCS

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_ALSA

.include <bsd.port.mk>
