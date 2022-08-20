PORTNAME=	ksanecore
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library providing logic to interface scanners

LIB_DEPENDS=	libsane.so:graphics/sane-backends

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=		ecm_build
USE_QT=		core gui widgets \
		buildtools_build qmake_build testlib_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
