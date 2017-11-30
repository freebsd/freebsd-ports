# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	k8048
PORTVERSION=	3.05
CATEGORIES=	devel
MASTER_SITES=	http://dev.kewl.org/k8048/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Programs Microchip PICs using Velleman K8048 board

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/${PORTNAME}/Src

USES=		gmake
ALL_TARGET=	build

BROKEN_armv6=	fails to compile: invokes x86 asm
BROKEN_armv7=	fails to compile: invokes x86 asm

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
