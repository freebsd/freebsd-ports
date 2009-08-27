# New ports collection makefile for: z80asm
# Date created: 29 Dec 2007
# Whom: Sean McLaughlin <sigma.zx@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	z80asm
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES=	http://nongnu.mirror.ironie.org/releases/${PORTNAME}/ \
		http://savannah.c3sl.ufpr.br/${PORTNAME}/

MAINTAINER=	sigma.zx@gmail.com
COMMENT=	Assembler for the Z80 microprcessor

USE_GMAKE=	yes
MAN1=		z80asm.1

post-patch:
	@${REINPLACE_CMD} -e 's#/bin/bash#/bin/sh#' ${WRKSRC}/Makefile

do-install:
	${INSTALL_MAN} ${WRKSRC}/z80asm.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/z80asm ${PREFIX}/bin

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/examples/hello.asm ${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/examples/macro.asm ${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/examples/seek.asm ${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/headers/msx-bios.asm ${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/headers/msx2+-bios.asm ${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/headers/msx2-bios.asm ${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/headers/msx2-subrom.asm ${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/headers/msxturbor-bios.asm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
