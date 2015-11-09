# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	tpasm
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ct0.com/pub/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-assembler for variety of microprocessors and controllers

BROKEN=		unfetchable

LICENSE=	GPLv2

USES=		gmake tar:tgz

PORTDOCS=	CONVERSION_C166.TXT MANUAL.TXT README*.TXT
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/* \
		${STAGEDIR}${PREFIX}/libdata/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
