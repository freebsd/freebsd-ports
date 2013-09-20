# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	tpasm
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ct0.com/pub/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-assembler for variety of microprocessors and controllers

LICENSE=	GPLv2

USES=		gmake

PORTDOCS=	CONVERSION_C166.TXT MANUAL.TXT README*.TXT
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/libdata/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/libdata/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
