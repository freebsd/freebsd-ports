# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>

PORTNAME=	squsq
PORTVERSION=	3.3
CATEGORIES=	archivers
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ NETBSD LOCAL/danfe
DISTNAME=	t20-squsq-3.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compressor/decompressor for CP/M "Squeeze" compressed files

CONFLICTS=	squirrel
WRKSRC=		${WRKDIR}/t20-squsq
MAKEFILE=	${FILESDIR}/Makefile
CFLAGS+=	-Wno-error=return-type

CONFLICTS_INSTALL=	sequoia squirrel # bin/sq

PLIST_FILES=	bin/sq bin/usq
PORTDOCS=	readme

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sq ${WRKSRC}/usq ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
