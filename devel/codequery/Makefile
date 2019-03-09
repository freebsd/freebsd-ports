# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	codequery
PORTVERSION=	0.21.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Code understanding, browsing and search tool

LICENSE=	MPL20 MIT
LICENSE_COMB=	multi

LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE.md
LICENSE_FILE_MIT=	${WRKSRC}/querylib/README.txt

USES=		cmake:insource compiler:c++11-lang ninja qt:5 sqlite
USE_QT=		concurrent core gui widgets xml  \
		buildtools_build linguisttools_build qmake_build
CMAKE_ON=	BUILD_QT5

USE_GITHUB=	yes
GH_ACCOUNT=	ruben2020

PLIST_FILES=	bin/codequery \
		bin/cqmakedb \
		bin/cqsearch
DESKTOP_ENTRIES="CodeQuery" "" "" "${PORTNAME}" "Development;" ""

post-patch:
	@${REINPLACE_CMD} 's,../build/gui/,,' ${WRKSRC}/gui/codequery.qrc

.include <bsd.port.mk>
