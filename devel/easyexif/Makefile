# $FreeBSD$

PORTNAME=	easyexif
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	devel

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Tiny ISO-compliant C++ EXIF parsing library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	mayanklahiri

SHEBANG_FILES=	test.sh

PLIST_FILES=	easyexif/bin/demo \
		easyexif/src/demo.cpp \
		easyexif/src/exif.cpp \
		include/exif.h

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include
	${CP} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/src
	${CP} ${WRKSRC}/*.cpp ${STAGEDIR}${PREFIX}/${PORTNAME}/src
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
	${STRIP_CMD} ${WRKSRC}/demo
	${CP} ${WRKSRC}/demo ${STAGEDIR}${PREFIX}/${PORTNAME}/bin

do-test:
	cd ${WRKSRC} && ./test.sh

.include <bsd.port.mk>
