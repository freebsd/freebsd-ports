# $FreeBSD$

PORTNAME=	kapidox
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 API Documentation Tools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource kde:5 python tar:xz
USE_KDE=	archive ecm
USE_QT5=	buildtools_build qmake_build
USE_PYTHON=	py3kplist

NO_ARCH=	yes

INSTALL_TARGET=	install

.include <bsd.port.mk>
