# Created by: Ryo MIYAMOTO
# $FreeBSD$

PORTNAME=	dungeon
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/games/source/:source \
		ftp://ftp.ifarchive.com/if-archive/games/source/:source \
		http://mirror.ifarchive.org/if-archive/games/source/:source \
		ftp://ftp.funet.fi/pub/misc/ifarchive/games/source/:source \
		http://ifarchive.flavorplex.com/if-archive/games/source/:source \
		http://eblong.com/zarf/glk/:glkterm
DISTFILES=	dungn27s.zip:source \
		dungn32b.zip:source \
		dungeon-gdt-glk.tar.gz:source \
		glkterm-104.tar.gz:glkterm
EXTRACT_ONLY=	dungeon-gdt-glk.tar.gz \
		glkterm-104.tar.gz \
		dungn27s.zip

MAINTAINER=	sailor@63bit.net
COMMENT=	Text adventure which became Zork I-III

USES=		ncurses
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/dungeon \
		man/man6/dungeon.6.gz \
		%%DATADIR%%/dundat \
		%%PORTDOCS%%%%DOCSDIR%%/dungn32b.zip
PLIST_DIRS=	%%DATADIR%%

PORTDOCS=	HISTORY MANIFEST README

MAKE_FLAGS+=	DATADIR=${DATADIR}
MAKE_ENV+=	GDT_FLAG=-DHAVE_GDT

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

pre-patch:
	@${REINPLACE_CMD} -e 's/^CC =/CC ?=/' \
		-e 's/^CFLAGS =/CFLAGS +=/' \
		-e 's/^OPTIONS = -g/OPTIONS =/' \
		-e "s@LIBS = @LIBS = ${LDFLAGS} @g" \
		-e '/^OPTIONS = -O/d' \
		${WRKSRC}/glkterm/Makefile ${WRKSRC}/dungeon-gdt/Makefile

do-build:
	@(cd ${WRKSRC}/glkterm && ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC}/dungeon-gdt/ && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS})

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/dungeon-gdt/dungeon \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dungeon-gdt/dundat ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/DUNGEON.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6/dungeon.6
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/dungn32b.zip ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
