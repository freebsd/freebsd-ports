# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	k8048
PORTVERSION=	3.05
CATEGORIES=	devel
MASTER_SITES=	http://dev.kewl.org/k8048/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Programs Microchip PICs using Velleman K8048 board

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

BROKEN_armv6=		invokes x86 assembler
BROKEN_armv7=		invokes x86 assembler
BROKEN_mips=		invokes x86 assembler
BROKEN_mips64=		invokes x86 assembler
BROKEN_sparc64=		invokes x86 assembler

USES=		gmake

WRKSRC=		${WRKDIR}/${PORTNAME}/Src

ALL_TARGET=	build

BINARY_ALIAS=	gcc=${CC}
PLIST_FILES=	bin/${PORTNAME} bin/kio ${BIN_SYMLINKS}

BIN_SYMLINKS=	bin/k12 bin/k14 bin/k16 bin/ktest

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 s|^CFLAGS=|CFLAGS+=| ; \
		 s|-ggdb||' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} kio ${STAGEDIR}${PREFIX}/bin)
.for i in ${BIN_SYMLINKS}
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/${i}
.endfor

.include <bsd.port.mk>
