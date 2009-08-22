# New ports collection makefile for:   libdisasm
# Date created:        18 January 2006
# Whom:                Lutz Boehne <lboehne@damogran.de>
#
# $FreeBSD$
#

PORTNAME=	libdisasm
PORTVERSION=	0.23
CATEGORIES=	devel
MASTER_SITES=	SF/bastard/${PORTNAME}/${PORTVERSION}

MAINTAINER=	bf1783@gmail.com
COMMENT=	The Bastard Disassembly Environment x86 disassembler library and CLI

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64

.ifndef(NOPORTDOCS)
PORTDOCS=	libdisasm.txt
.endif

MAN1=	x86dis.1
MAN3=	x86_disasm.3 x86_format_insn.3 x86_init.3
MAN7=	libdisasm.7

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
