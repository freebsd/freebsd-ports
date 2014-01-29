# Created by: Sean McLaughlin <sigma.zx@gmail.com>
# $FreeBSD$

PORTNAME=	z80asm
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES=	http://nongnu.mirror.ironie.org/releases/${PORTNAME}/ \
		http://savannah.c3sl.ufpr.br/${PORTNAME}/

MAINTAINER=	sigma.zx@gmail.com
COMMENT=	Assembler for the Z80 microprocessor

OPTIONS_DEFINE=	EXAMPLES

USES=		gmake

post-patch:
	@${REINPLACE_CMD} -e 's#/bin/bash#/bin/sh#' ${WRKSRC}/Makefile

do-install:
	${INSTALL_MAN} ${WRKSRC}/z80asm.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/z80asm ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/examples/hello.asm ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/examples/macro.asm ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/examples/seek.asm ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/headers/msx-bios.asm ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/headers/msx2+-bios.asm ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/headers/msx2-bios.asm ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/headers/msx2-subrom.asm ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/headers/msxturbor-bios.asm ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
