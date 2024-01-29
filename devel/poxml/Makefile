PORTNAME=	poxml
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tools to translate Docbook XML using gettext

USES=		cmake compiler:c++11-lang gettext-tools:build,run \
		kde:5 qt:5 tar:xz
USE_KDE=	doctools ecm:build
USE_QT=		core xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
