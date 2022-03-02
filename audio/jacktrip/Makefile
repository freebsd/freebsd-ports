PORTNAME=	jacktrip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	b3a73695ba1788274ca19b7f00f4c06e2b41649b.diff:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-machine audio network performance over the Internet

LICENSE=	MIT

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libjack.so:audio/jack

USES=		compiler:c++11-lang gl pkgconfig qmake qt:5
USE_QT=		core gui network widgets buildtools_build
USE_GL=		gl

USE_GITHUB=	yes

QMAKE_SOURCE_PATH=	${PORTNAME}.pro

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/jacktrip.1.gz

.include <bsd.port.mk>
