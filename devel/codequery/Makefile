# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	codequery
PORTVERSION=	0.21.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Code understanding, browsing and search tool

LICENSE=	MPL20 MIT
LICENSE_COMB=	multi

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE.md
LICENSE_FILE_MIT=	${WRKSRC}/querylib/README.txt

USES=		cmake:insource compiler:c++11-lang ninja qt:4 sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	ruben2020

USE_QT=		linguisttools_build moc_build rcc_build uic_build \
		corelib gui qmake xml

PLIST_FILES=	bin/codequery \
		bin/cqmakedb \
		bin/cqsearch
DESKTOP_ENTRIES="CodeQuery" "" "" "${PORTNAME}" "Development;" ""

post-patch:
	@${REINPLACE_CMD} 's,../build/gui/,,' ${WRKSRC}/gui/codequery.qrc

.include <bsd.port.mk>
