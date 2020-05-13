# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abseil
PORTVERSION=	20200225.2
CATEGORIES=	devel
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	567bee2f7393.diff:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Abseil Common Libraries (C++)

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-cpp

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON

post-install:
# XXX: should fix CMakeLists.txt instead of removing empty directories
	${RMDIR} ${STAGEDIR}${PREFIX}/include/absl/copts \
		${STAGEDIR}${PREFIX}/include/absl/strings/testdata
	${RM} -r ${STAGEDIR}${PREFIX}/include/absl/time/internal/cctz/testdata

.include <bsd.port.mk>
