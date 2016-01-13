# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-readline
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Readline interface for the Pure language

LICENSE=	BSD3CLAUSE GPLv3
LICENSE_COMB=	dual

USES=		pkgconfig pure readline
PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

PLIST_FILES=	lib/pure/readline.pure \
		lib/pure/readline.so

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pure/readline.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
