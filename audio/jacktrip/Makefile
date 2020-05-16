# $FreeBSD$

PORTNAME=	jacktrip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1-132
DISTVERSIONSUFFIX=	-g5dd7740
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-machine audio network performance over the Internet

LICENSE=	MIT

LIB_DEPENDS=	libjack.so:audio/jack

USES=		qt:5 qmake
USE_GITHUB=	yes
USE_QT=		core network buildtools_build

CXXFLAGS+=	-D__LINUX__

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/jacktrip

.include <bsd.port.mk>
