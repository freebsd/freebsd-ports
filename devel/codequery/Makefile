PORTNAME=	codequery
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27.0
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Code understanding, browsing and search tool
WWW=		https://ruben2020.github.io/codequery/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake compiler:c++11-lang qt:5 sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	ruben2020

USE_QT=		concurrent core gui widgets xml buildtools:build \
		linguisttools:build qmake:build

DESKTOP_ENTRIES=	"CodeQuery" \
			"" \
			"" \
			"${PORTNAME}" \
			"Development;" \
			""

PLIST_FILES=	bin/codequery \
		bin/cqmakedb \
		bin/cqsearch

.include <bsd.port.mk>
