# $FreeBSD$

PORTNAME=	kapidox
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 API Documentation Tools

LICENSE=	BSD2CLAUSE

USES=		cmake:insource kde:5 python qt:5 shebangfix tar:xz
USE_KDE=	archive ecm
USE_QT=		buildtools_build qmake_build
USE_PYTHON=	distutils noflavors py3kplist

NO_ARCH=	yes

INSTALL_TARGET=	install

SHEBANG_FILES=	${WRKSRC}/setup.py

.include <bsd.port.mk>
