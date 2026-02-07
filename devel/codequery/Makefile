PORTNAME=	codequery
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Code understanding, browsing and search tool
WWW=		https://ruben2020.github.io/codequery/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake gl qt:6 sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	ruben2020
USE_GL=		opengl
USE_QT=		5compat base translations

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
