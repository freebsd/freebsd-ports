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

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		webbench.1
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	copyright changelog
.endif

PLIST_FILES=	bin/webbench

NO_STAGE=	yes
do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/webbench ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
		${INSTALL_MAN} ${WRKSRC}/webbench.1 ${MAN1PREFIX}/man/man1
.endif
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/debian/copyright ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DOCSDIR}
.endif

.include <bsd.port.mk>
