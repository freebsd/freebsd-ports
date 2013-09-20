# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	par
PORTVERSION=	0.03.01
CATEGORIES=	archivers games
MASTER_SITES=	http://ibiblio.org/pub/linux/games/quake/
PKGNAMEPREFIX=	quake-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Archiver for Quake I and II packed data files

LICENSE=	GPLv2

CONFLICTS=	par-[0-9]*

NO_STAGE=	yes
MAKEFILE=	Makefile.Linux
MAKE_ARGS=	CC="${CC}"

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,-Wall.*-pipe,${CFLAGS}, ; \
		s,"Linux,"${OPSYS},' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's,off_t,uint32_t,g' ${WRKSRC}/par.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
