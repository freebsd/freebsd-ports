# New ports collection makefile for:   paq
# Date created:                5 April 2007
# Whom:                        bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	paq
PORTVERSION=	8.l
CATEGORIES=	archivers
MASTER_SITES=	http://www.cs.fit.edu/~mmahoney/compression/
DISTNAME=	paq8l

MAINTAINER=	bf2006a@yahoo.com
COMMENT=	An archiver with an extremely high compression ratio

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	DISTNAME=${DISTNAME}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ASM) && ${ARCH} == "i386" && !defined(PACKAGE_BUILDING)
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
CXXFLAGS+=	-DUNIX -Os
ASM1?=	nasm -f elf -o
ASM2?=
.if !defined(WITH_SSE)
ASMFILE=	paq7asm
.else
ASMFILE=	paq7asmsse
.endif
STRIP=
.elif !defined(WITHOUT_ASM) && ${ARCH} == "amd64" && !defined(PACKAGE_BUILDING)
BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm
CXXFLAGS+=	-DUNIX -Os
ASM1?=	yasm -f elf64 -o
ASM2?=	-a x86 -m amd64
ASMFILE=	paq7asm-x86_64
STRIP=
.else
WITHOUT_ASM=	yes
CXXFLAGS+=	-DUNIX -DNOASM -Os
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you have an older (pre-1997) x86 CPU without MMX instruction"
	@${ECHO_MSG} "support, or if you wish to use the (usually slower) C++ code"
	@${ECHO_MSG} "instead of the equivalent assembly language routines that are"
	@${ECHO_MSG} "enabled by default on x86 and amd64 architectures, hit Ctrl-C"
	@${ECHO_MSG} "now and use \"make WITHOUT_ASM=yes\"."
	@${ECHO_MSG}
	@${ECHO_MSG} "If you wish to use the version of the assembly code that is"
	@${ECHO_MSG} "optimized for x86 (not amd64) processors with SSE instruction"
	@${ECHO_MSG} "support, hit Ctrl-C now and use \"make WITH_SSE=yes\"."
	@${ECHO_MSG}

do-build:
.if !defined(WITHOUT_ASM)
	${ASM1} ${WRKSRC}/${ASMFILE}.o ${ASM2} ${WRKSRC}/${ASMFILE}.asm
	${CXX} ${WRKSRC}/${DISTNAME}.cpp ${CXXFLAGS} -o ${WRKSRC}/${DISTNAME} ${WRKSRC}/${ASMFILE}.o
.else
	${CXX} ${WRKSRC}/${DISTNAME}.cpp ${CXXFLAGS} -o ${WRKSRC}/${DISTNAME}
.endif

do-install:
.if !exists(${PREFIX}/bin)
	${MKDIR} ${PREFIX}/bin
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
.if !exists(${DOCSDIR})
	${MKDIR} ${DOCSDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/${DISTNAME}.cpp ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
