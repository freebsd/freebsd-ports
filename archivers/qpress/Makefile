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

PLIST_FILES=	bin/qpress

do-build:
	cd ${WRKSRC} && \
	${CXX} ${CXXFLAGS} -o qpress -x c quicklz.c -x c++ qpress.cpp aio.cpp utilities.cpp -lpthread
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qpress ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
