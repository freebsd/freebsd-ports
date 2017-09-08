# $FreeBSD$

PORTNAME=	pasm
PORTVERSION=	0.84
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TI PRU Assembler

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/pru_sw/utils/LICENCE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	rpaulo
GH_PROJECT=	am335x_pru_package
PLIST_FILES=	bin/pasm

USES=		alias

do-build:
	(cd ${WRKSRC}/pru_sw/utils/pasm_source && \
		${CC} ${CFLAGS} -D_UNIX_ pasm.c pasmpp.c pasmexp.c pasmop.c \
		pasmdot.c pasmstruct.c pasmmacro.c -o pasm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pru_sw/utils/pasm_source/pasm ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
