PORTNAME=	extract-xiso
DISTVERSIONPREFIX=	build-
DISTVERSION=	202505152050
CATEGORIES=	archivers

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Create, modify, and extract XISOs

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USE_GITHUB=	yes
GH_ACCOUNT=	XboxDev

PLIST_FILES=	bin/extract-xiso

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} \
		-o ${WRKDIR}/extract-xiso ${WRKSRC}/extract-xiso.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/extract-xiso ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
