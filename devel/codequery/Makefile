PORTNAME=	codequery
PORTVERSION=	0.25.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Code understanding, browsing and search tool

LICENSE=	MPL20 MIT
LICENSE_COMB=	multi

LICENSE_FILE_MIT=	${WRKSRC}/querylib/README.txt
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE.md

USES=		cmake:insource compiler:c++11-lang ninja qt:5 sqlite
		
USE_GITHUB=	yes
GH_ACCOUNT=	ruben2020

USE_QT=		concurrent core gui widgets xml  \
		buildtools_build linguisttools_build qmake_build

CMAKE_ON=	BUILD_QT5

DESKTOP_ENTRIES="CodeQuery" "" "" "${PORTNAME}" "Development;" ""

PLIST_FILES=	bin/codequery \
		bin/cqmakedb \
		bin/cqsearch

.include <bsd.port.mk>
