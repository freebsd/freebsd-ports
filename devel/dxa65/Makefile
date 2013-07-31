# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	dxa
PORTVERSION=	0.1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.floodgap.com/retrotech/xa/dists/
PKGNAMESUFFIX=	65

MAINTAINER=	uffe@uffe.org
COMMENT=	Disassembler for MOS 6502 and compatible CPUs

OPTIONS_DEFINE=	DOCS

USES=	gmake

MAN1=	dxa.1
MLINKS=	dxa.1 dxa65.1

PLIST_FILES=	bin/dxa65
PORTDOCS=	INSTALL

.include <bsd.port.options.mk>

post-patch-script:
	@${REINPLACE_CMD} 's|CC = |CC ?= |g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|CFLAGS = |CFLAGS ?= |g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dxa ${PREFIX}/bin/dxa65
	${INSTALL_MAN} ${WRKSRC}/dxa.1 ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
.endif

.include <bsd.port.mk>
