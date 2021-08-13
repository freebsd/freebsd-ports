PORTNAME=	libkcddb
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE CDDB library

LIB_DEPENDS=	libmusicbrainz5.so:audio/libmusicbrainz5

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets \
		coreaddons i18n jobwidgets kio service solid \
		widgetsaddons windowsystem \
		ecm_build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
