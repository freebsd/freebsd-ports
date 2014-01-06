# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	webbench
PORTVERSION=	1.5
CATEGORIES=	benchmarks www
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/servers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple forking web benchmark

MAKE_ARGS+=	CFLAGS="${CPPFLAGS} ${CFLAGS}"

PORTDOCS=	copyright changelog

PLIST_FILES=	bin/webbench \
		man/man1/webbench.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webbench ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webbench.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/copyright ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
