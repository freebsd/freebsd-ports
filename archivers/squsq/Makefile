PORTNAME=	squsq
PORTVERSION=	3.3
CATEGORIES=	archivers
MASTER_SITES=	NETBSD LOCAL/danfe
DISTNAME=	t20-squsq-3.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compressor/decompressor for CP/M "Squeeze" compressed files

LICENSE=	NONE

MAKEFILE=	${FILESDIR}/Makefile

CFLAGS+=	-Wno-error=return-type

CONFLICTS=	squirrel
CONFLICTS_INSTALL=	sequoia squirrel # bin/sq

WRKSRC=		${WRKDIR}/t20-squsq

PLIST_FILES=	bin/sq bin/usq
PORTDOCS=	readme

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sq ${WRKSRC}/usq ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
