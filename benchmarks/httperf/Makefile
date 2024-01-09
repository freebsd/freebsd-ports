PORTNAME=	httperf
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	benchmarks www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for measuring web server performance
WWW=		https://github.com/httperf/httperf

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool ssl
USE_GITHUB=	yes
GH_TAGNAME=	568322e
MAKE_ARGS=	LIBUTIL_OBJS=ssl_writev.o \
		exec_prefix=${PREFIX}

PLIST_FILES=	bin/httperf \
		share/man/man1/httperf.1.gz
PORTDOCS=	ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
