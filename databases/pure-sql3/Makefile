# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-sql3
PORTVERSION=	0.5
CATEGORIES=	databases
MASTER_SITES=	https://bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure language binding to the SQLite3 library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig pure sqlite
PORTDOCS=	README
PORTEXAMPLES=	*
OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	lib/pure/sql3.pure \
		lib/pure/sql3util.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pure/sql3util.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
