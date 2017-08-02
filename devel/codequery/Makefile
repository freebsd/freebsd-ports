# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	codequery
PORTVERSION=	0.21.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Code understanding, browsing and search tool

LICENSE=	MPL20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE.md
LICENSE_FILE_MIT=	${WRKSRC}/querylib/README.txt

USES=		cmake ninja sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	ruben2020

USE_QT4=	linguisttools_build moc_build rcc_build uic_build \
		corelib gui qmake xml

PLIST_FILES=	bin/codequery \
		bin/cqmakedb \
		bin/cqsearch
DESKTOP_ENTRIES="CodeQuery" "" "" "${PORTNAME}" "Development;" ""

post-patch:
	@${REINPLACE_CMD} 's,../build/gui/,,' ${WRKSRC}/gui/codequery.qrc

.include <bsd.port.mk>
