PORTNAME=	help
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt online help integration module

USES=		compiler:c++11-lang perl5 qmake qt-dist:5,tools
USE_PERL5=	build
USE_QT=		core gui network sql widgets \
		buildtools:build sql-sqlite3:run

QT_BINARIES=	yes

.include <bsd.port.mk>
