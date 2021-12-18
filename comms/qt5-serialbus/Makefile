PORTNAME=	serialbus
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	comms
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt functions to access industrial bus systems

USES=		compiler:c++11-lib perl5 qmake qt-dist:5,serialbus
USE_PERL5=	extract
USE_QT=		core network serialport buildtools_build
QT_BINARIES=	yes

.include <bsd.port.mk>
