PORTNAME=	sqliteconvert
DISTVERSIONPREFIX=	VERSION_
DISTVERSION=	0_1_2
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools to convert SQLite3 schema files into documentation

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	dot:graphics/graphviz

USE_GITHUB=	yes
GH_ACCOUNT=	kristapsdz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sqlite2html \
		${STAGEDIR}${PREFIX}/bin/sqlite2dot

.include <bsd.port.mk>
