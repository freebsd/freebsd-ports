PORTNAME=	qaudiosonar
DISTVERSIONPREFIX=	v
DISTVERSION=		1.8.3
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick Audio Sonar
WWW=		https://github.com/hselasky/qaudiosonar

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjack.so:audio/jack

USES=		compiler:c++17-lang gl qmake qt:6 tar:bzip2
USE_GL=		gl
USE_QT=		base

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

PLIST_FILES= \
	bin/qaudiosonar \
	share/pixmaps/qaudiosonar.png \
	share/applications/qaudiosonar.desktop

.include <bsd.port.mk>
