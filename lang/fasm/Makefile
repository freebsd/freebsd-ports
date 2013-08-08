# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	fasm
PORTVERSION=	1.71.12
CATEGORIES=	lang devel
MASTER_SITES=	http://flatassembler.net/

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Flat, multiple-pass assembler for IA-32 & x86-64 architectures

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/license.txt

ONLY_FOR_ARCHS=	i386 amd64 ia64
IA32_BINARY_PORT=	yes

PLIST_FILES=	bin/fasm
PORTDOCS=	*
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
CFLAGS+=		-m32 -L/usr/lib32 -B/usr/lib32
.endif

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} fasm.o -o fasm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fasm ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
