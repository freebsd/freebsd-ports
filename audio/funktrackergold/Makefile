# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	funktrackergold
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players
DISTNAME=	funktrackergold-1.5-2
EXTRACT_SUFX=	.tgz

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Curses MOD/FNK music tracker

OPTIONS_DEFINE=	DOCS

LICENSE=	GPLv2

USES=		compiler:nestedfct

WRKSRC=		${WRKDIR}/funkgold
MAKE_ARGS=	EXTRA_CFLAGS="${PTHREAD_CFLAGS}" \
		EXTRA_LDFLAGS="${PTHREAD_LIBS}"

PORTDOCS=	INSTALL
PLIST_FILES=	bin/funkgold

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/funkgold ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
