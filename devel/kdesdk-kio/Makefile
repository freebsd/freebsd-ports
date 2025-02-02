PORTNAME=	kdesdk-kio
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KIO workers useful for software development
WWW=		https://kde.org/

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 shebangfix tar:xz
USE_KDE=	config coreaddons i18n kio service \
		ecm:build
USE_QT=		base

SHEBANG_FILES=	perldoc/pod2html.pl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
