# New ports collection makefile for:	crafty
# Date created:				31 May 1998
# Whom:					Stefan Eggers <seggers@semyam.dinoco.de>
#
# $FreeBSD$
#

PORTNAME=	crafty
PORTVERSION=	19.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cis.uab.edu/pub/hyatt/common/:data \
		ftp://ftp.cis.uab.edu/pub/hyatt/doc/:doc \
		ftp://ftp.cis.uab.edu/pub/hyatt/v${PORTVERSION:R}/:src
DISTFILES=	crafty-${PORTVERSION}.tar.gz:src \
		start.pgn.gz:data

MAINTAINER=	seggers@semyam.dinoco.de
COMMENT=	A chess programm for playing and analyzing games

.if !defined(NOPORTDOCS)
DOCFILES=	crafty.doc.ascii crafty.doc.ps
DISTFILES+=	${DOCFILES:S/$/:doc/}
.endif

ALL_TARGET=	crafty

OPT=		-DCOMPACT_ATTACKS -DUSE_ATTACK_FUNCTIONS
.if ${MACHINE_ARCH} == "i386"
MAKE_ENV+=	asm=X86-elf.o
OPT+=		-DUSE_ASSEMBLY_A -DUSE_ASSEMBLY_B -DFAST
# XXX Someone with ASM knowledge would have to fix the Sparc.S
.elif ${MACHINE_ARCH} == "sparc64" && defined(CRAFTY_SPARC_ASM)
MAKE_ENV+=	asm=Sparc.o
OPT+=		-DUSE_ASSEMBLY_A
.else
OPT+=		-DFAST
.endif
MAKE_ENV+=	opt="${OPT}" target=${OPSYS} CXFLAGS="${CXXFLAGS}"

DIST_SUBDIR=	crafty
EXTRACT_ONLY=	crafty-${PORTVERSION}.tar.gz

MAN6=		crafty.6

post-extract:
	${GUNZIP_CMD} <${DISTDIR}/${DIST_SUBDIR}/start.pgn.gz >${WRKSRC}/start.pgn
	${MV} ${WRKSRC}/Sparc.s ${WRKSRC}/Sparc.S
.ifdef CRAFTY_SPARC_ASM
	########################################################
	#
	# Sparc.S is known to segfault! Use at your own risk or
	# turn off the CRAFTY_SPARC_ASM defined
	#
	########################################################
.endif

post-build:
	(cd ${WRKSRC}; ./crafty <${FILESDIR}/books-building)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crafty ${PREFIX}/bin/crafty
	${MKDIR} ${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKSRC}/books.bin ${PREFIX}/lib/crafty/books.bin
	${INSTALL_MAN} ${FILESDIR}/crafty.6 ${MANPREFIX}/man/man6/crafty.6
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif

.include <bsd.port.mk>
