PORTNAME=	remoteobjects
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 Remote Objects module

USES=		compiler:c++11-lang gl perl5 qmake qt-dist:5
USE_GL=		gl
USE_PERL5=	build
USE_QT=		core declarative network \
		buildtools:build

QT_BINARIES=	yes

.include <bsd.port.mk>
