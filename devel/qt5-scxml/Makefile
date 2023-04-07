PORTNAME=	scxml
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 SCXML module

USES=		compiler:c++11-lang perl5 qmake qt-dist:5,scxml
USE_PERL5=	build
USE_QT=		core declarative network buildtools:build

QT_BINARIES=	yes

.include <bsd.port.mk>
