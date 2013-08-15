# $FreeBSD$

PORTNAME=	pasm
PORTVERSION=	0.84
CATEGORIES=	devel
MASTER_SITES=	https://github.com/rpaulo/am335x_pru_package/archive/

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	TI PRU Assembler

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/pru_sw/utils/LICENCE.txt

WRKSRC=		${WRKDIR}/am335x_pru_package-${PORTNAME}-${PORTVERSION}
FETCH_ARGS=	"-Fpr"
PLIST_FILES=	bin/pasm

do-build:
	(cd ${WRKSRC}/pru_sw/utils/pasm_source && \
		${CC} ${CFLAGS} -D_UNIX_ pasm.c pasmpp.c pasmexp.c pasmop.c \
		pasmdot.c pasmstruct.c pasmmacro.c -o pasm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pru_sw/utils/pasm_source/pasm ${PREFIX}/bin

.include <bsd.port.mk>
