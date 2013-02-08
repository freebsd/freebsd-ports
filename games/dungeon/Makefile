# Created by: Ryo MIYAMOTO
# $FreeBSD$

PORTNAME=	dungeon
PORTVERSION=	3.2
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

NO_WRKSUBDIR=	yes
MAN6=		dungeon.6

PLIST_FILES=	bin/dungeon \
		%%DATADIR%%/dundat \
		%%PORTDOCS%%%%DOCSDIR%%/dungn32b.zip
PLIST_DIRS=	%%DATADIR%%

PORTDOCS=	HISTORY MANIFEST README

MAKE_FLAGS+=	DATADIR=${DATADIR}
MAKE_ENV+=	GDT_FLAG=-DHAVE_GDT

.include <bsd.port.options.mk>

pre-patch:
	@${REINPLACE_CMD} -e 's/^CC =/CC ?=/' \
		-e 's/^CFLAGS =/CFLAGS +=/' \
		-e 's/^OPTIONS = -g/OPTIONS =/' \
		-e '/^OPTIONS = -O/d' \
		${WRKSRC}/glkterm/Makefile ${WRKSRC}/dungeon-gdt/Makefile

do-build:
	@(cd ${WRKSRC}/glkterm && ${MAKE})
	@(cd ${WRKSRC}/dungeon-gdt/ && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS})

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/dungeon-gdt/dungeon ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dungeon-gdt/dundat ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/DUNGEON.6 ${MAN6PREFIX}/man/man6/dungeon.6
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/dungn32b.zip ${DOCSDIR}
.endif

.include <bsd.port.mk>
