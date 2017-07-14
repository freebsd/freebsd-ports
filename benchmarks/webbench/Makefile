# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	webbench
PORTVERSION=	1.5
CATEGORIES=	benchmarks www
MASTER_SITES=	SUNSITE/apps/www/servers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple forking web benchmark

LICENSE=	GPLv2

MAKE_ARGS=	CFLAGS="${CPPFLAGS} ${CFLAGS}"

PORTDOCS=	ChangeLog

PLIST_FILES=	bin/webbench \
		man/man1/webbench.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webbench ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webbench.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
