PORTNAME=	funktrackergold
DISTVERSION=	1.5-2
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/players

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses MOD/FNK music tracker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Software looks abandoned: last release is in 1999 and WWW link had nothing to do with the software. Does not build with GCC 14.2
EXPIRATION_DATE=2024-10-30

BROKEN_armv6=		fails to compile: function definition is not allowed here
BROKEN_armv7=		fails to compile: function definition is not allowed here

USES=		compiler:nestedfct ncurses tar:tgz

WRKSRC=		${WRKDIR}/funkgold
MAKE_ARGS=	EXTRA_LDFLAGS="-lpthread"

PORTDOCS=	INSTALL
PLIST_FILES=	bin/funkgold

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/funkgold ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
