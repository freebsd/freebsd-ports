# New ports collection makefile for:   paq
# Date created:                5 April 2007
# Whom:                        bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	paq
DISTVERSION=	8o9
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	http://www.cs.fit.edu/~mmahoney/compression/
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A family of archivers with extremely high compression ratios

LPAQ=		lpaq8
LPQ=		lpq1
PAQ9=		paq9a
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LPAQ}${EXTRACT_SUFX} ${LPQ}v2${EXTRACT_SUFX} \
		${PAQ9}${EXTRACT_SUFX}
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
SUB_FILES=	pkg-message
CPPFILE=	${PORTNAME}${DISTVERSION:C/v.([^\.]*)$/\1/}
PLIST_SUB+=	CPPFILE=${CPPFILE} LPAQ=${LPAQ}	LPQ=${LPQ} PAQ9=${PAQ9}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ASM) && ${ARCH} == "i386" && !defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
PAQFLAGS+=	-DUNIX
ASM1?=	nasm -f elf -o
ASM2?=	-Ox
.if !defined(WITH_SSE2)
ASMFILE=	paq7asm
.else
ASMFILE=	paq7asmsse
.endif
STRIP=
.elif !defined(WITHOUT_ASM) && ${ARCH} == "amd64" && !defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
PAQFLAGS+=	-DUNIX
ASM1?=	yasm -f elf64 -o
ASM2?=	-a x86 -m amd64
ASMFILE=	paq7asm-x86_64
STRIP=
.else
WITHOUT_ASM=	yes
PAQFLAGS+=	-DUNIX -DNOASM
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
	@${ECHO_MSG} "optimized for x86 or amd64 processors with SSE2 instruction"
	@${ECHO_MSG} "support that are running in 32-bit mode, hit Ctrl-C now and use"
	@${ECHO_MSG} "\"make WITH_SSE2=yes\"."
	@${ECHO_MSG}
	@${ECHO_MSG} "This software is computationally demanding, and users are"
	@${ECHO_MSG} "advised to employ compiler optimizations when building it."
	@${ECHO_MSG} "In particular, authors of this software have used such flags"
	@${ECHO_MSG} "as \"-O2\" to advantage."
	@${ECHO_MSG}

do-build:
.if !defined(WITHOUT_ASM)
	${ASM1} ${WRKSRC}/${ASMFILE}.o ${ASM2} ${WRKSRC}/${ASMFILE}.asm
	${CXX} ${WRKSRC}/${CPPFILE}.cpp ${CXXFLAGS} ${PAQFLAGS} -o ${WRKSRC}/${CPPFILE} \
	${WRKSRC}/${ASMFILE}.o
.else
	${CXX} ${WRKSRC}/${CPPFILE}.cpp ${CXXFLAGS} ${PAQFLAGS} -o ${WRKSRC}/${CPPFILE}
.endif
.if ${ARCH} == "alpha" || ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
PLIST_SUB+=	THIRTYTWO="@comment "
.else
	${CXX} ${WRKSRC}/${LPAQ}.cpp ${CXXFLAGS} -o ${WRKSRC}/${LPAQ}
	${CXX} ${WRKSRC}/${LPAQ}.cpp ${CXXFLAGS} -DWIKI -o ${WRKSRC}/${LPAQ}e
	${CXX} ${WRKSRC}/${LPQ}.cpp ${CXXFLAGS} -o ${WRKSRC}/${LPQ}
	${CXX} ${WRKSRC}/${PAQ9}.cpp ${CXXFLAGS} -o ${WRKSRC}/${PAQ9}
PLIST_SUB+=	THIRTYTWO=""
.endif

do-install:
.if !exists(${PREFIX}/bin)
	${MKDIR} ${PREFIX}/bin
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/${CPPFILE} ${PREFIX}/bin
.if ${ARCH} != "alpha" && ${ARCH} != "amd64" && ${ARCH} != "ia64" && ${ARCH} != "sparc64"
	${INSTALL_PROGRAM} ${WRKSRC}/${LPAQ} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${LPAQ}e ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${LPQ} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PAQ9} ${PREFIX}/bin
.endif
.if !defined(NOPORTDOCS)
.if !exists(${DOCSDIR})
	${MKDIR} ${DOCSDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/${CPPFILE}.cpp ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/Readme.txt ${DOCSDIR}/${CPPFILE}_readme.txt
.if ${ARCH} != "alpha" && ${ARCH} != "amd64" && ${ARCH} != "ia64" && ${ARCH} != "sparc64"
	${INSTALL_MAN} ${WRKSRC}/${LPAQ}.cpp ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${LPQ}.cpp ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PAQ9}.cpp ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/Readme.txt ${DOCSDIR}/${CPPFILE}_readme.txt
	${INSTALL_MAN} ${WRKSRC}/readme.txt ${DOCSDIR}/${LPAQ}_readme.txt
.endif
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
