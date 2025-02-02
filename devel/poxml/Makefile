PORTNAME=	poxml
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tools to translate Docbook XML using gettext

USES=		cmake compiler:c++11-lang gettext-tools:build,run kde:6 qt:6 \
		tar:xz
USE_KDE=	doctools \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
