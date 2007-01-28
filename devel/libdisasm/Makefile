# New ports collection makefile for:   libdisasm
# Date created:        18 January 2006
# Whom:                Lutz Boehne <lboehne@damogran.de>
#
# $FreeBSD$
#

PORTNAME=	libdisasm
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bastard
DISTNAME=	libdisasm-0.21-pre3
EXTRACT_SUFX=	.tgz

MAINTAINER=	lboehne@damogran.de
COMMENT=	The Bastard Disassembly Environment x86 disassembler library

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's, make, gmake,' ${WRKSRC}/Makefile
.if ${OSVERSION} < 500000
	${REINPLACE_CMD} -e 's, -Wno-strict-aliasing,,' ${WRKSRC}/libdisasm/Makefile
.endif

.if !defined(NOPORTDOCS)
DOCSDIR=	${DATADIR}/doc
DOCS=	libdisasm.txt
.endif

MAN3=	x86_disasm.3 x86_format_insn.3 x86_init.3
MAN7=	libdisasm.7

do-install:
	${INSTALL_DATA} ${WRKSRC}/libdisasm/libdisasm.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libdisasm/libdisasm.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libdisasm/libdis.h ${PREFIX}/include
	${MKDIR} ${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/libdisasm/ia32_opcode.dat ${DATADIR}/data
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif
.for i in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man3
.endfor
.for i in ${MAN7}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man7
.endfor

.include <bsd.port.post.mk>
