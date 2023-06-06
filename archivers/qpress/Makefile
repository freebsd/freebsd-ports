PORTNAME=	qpress
PORTVERSION=	20230507
CATEGORIES=	archivers

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Portable file archiver using QuickLZ
WWW=		https://github.com/PierreLvx/qpress

LICENSE=	GPLv2

USES=		dos2unix
USE_GITHUB=	yes
GH_ACCOUNT=	PierreLvx
GH_TAGNAME=	${PORTVERSION}

PLIST_FILES=	bin/qpress

do-build:
	cd ${WRKSRC} && \
	${CXX} ${CXXFLAGS} -o qpress qpress.cpp aio.cpp quicklz.c utilities.cpp -lpthread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qpress ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
