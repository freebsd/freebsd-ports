# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	fasm
PORTVERSION=	1.73.17
CATEGORIES=	lang devel
MASTER_SITES=	https://flatassembler.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flat, multiple-pass assembler for IA-32 & x86-64 architectures

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

ONLY_FOR_ARCHS=		amd64 i386
IA32_BINARY_PORT=	yes

PLIST_FILES=	bin/fasm
PORTDOCS=	*
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
CFLAGS+=	-m32 -L/usr/lib32 -B/usr/lib32
.endif

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} fasm.o -o fasm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fasm ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
