# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	funktrackergold
DISTVERSION=	1.5-2
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/players

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses MOD/FNK music tracker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to compile: function definition is not allowed here
BROKEN_armv7=		fails to compile: function definition is not allowed here
BROKEN_mips=		fails to compile: nested functions are disabled, use -fnested-functions to re-enable
BROKEN_mips64=		fails to compile: nested functions are disabled, use -fnested-functions to re-enable
BROKEN_powerpc64=	fails to compile: nested functions are disabled, use -fnested-functions to re-enable

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
