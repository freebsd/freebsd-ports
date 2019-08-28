# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abseil
PORTVERSION=	g20190703
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Abseil Common Libraries (C++)

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-cpp
GH_TAGNAME=	74d9175

post-install:
# XXX: should fix CMakeLists.txt instead of removing empty directories
	${RMDIR} ${STAGEDIR}${PREFIX}/include/absl/copts \
		${STAGEDIR}${PREFIX}/include/absl/strings/testdata
	${RM} -r ${STAGEDIR}${PREFIX}/include/absl/time/internal/cctz/testdata

.include <bsd.port.mk>
