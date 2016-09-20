# Created by: Lutz Boehne <lboehne@damogran.de>
# $FreeBSD$

PORTNAME=	libdisasm
PORTVERSION=	0.23
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/bastard/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bastard Disassembly Environment x86 disassembler library and CLI

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	libdisasm.txt

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdisasm.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/libdisasm.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
