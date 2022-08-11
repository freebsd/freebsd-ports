PORTNAME=	par
PORTVERSION=	0.03.01
CATEGORIES=	archivers games
MASTER_SITES=	http://ibiblio.org/pub/linux/games/quake/
PKGNAMEPREFIX=	quake-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Archiver for Quake I and II packed data files

LICENSE=	GPLv2

CONFLICTS=	par_format # bin/par 

MAKEFILE=	Makefile.Linux
MAKE_ARGS=	CC="${CC}"

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,-Wall.*-pipe,${CFLAGS}, ; \
		s,"Linux,"${OPSYS},' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's,off_t,uint32_t,g' ${WRKSRC}/par.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
