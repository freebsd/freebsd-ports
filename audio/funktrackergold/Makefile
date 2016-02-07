# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	funktrackergold
DISTVERSION=	1.5-2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/players

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses MOD/FNK music tracker

OPTIONS_DEFINE=	DOCS

LICENSE=	GPLv2

USES=		compiler:nestedfct ncurses tar:tgz

WRKSRC=		${WRKDIR}/funkgold
MAKE_ARGS=	EXTRA_LDFLAGS="-lpthread"

PORTDOCS=	INSTALL
PLIST_FILES=	bin/funkgold

BROKEN_powerpc64=	Does not build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/funkgold ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
