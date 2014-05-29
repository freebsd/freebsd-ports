# Created by: Ben Haga <tuximus@tuximus.mine.nu>
# $FreeBSD$

PORTNAME=	tigcc
PORTVERSION=	0.96.b8
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=		${MASTER_SITE_GCC:S/$/:gcc/} \
			${MASTER_SITE_GNU:S/$/:gas/} \
			http://tigcc.ticalc.org/linux/:tigcc
MASTER_SITE_SUBDIR=	snapshots/4.1-20060728/:gcc \
			binutils/:gas
DISTFILES=		gcc-core-4.1-20060728.tar.bz2:gcc \
			binutils-2.16.1.tar.bz2:gas \
			tigcc_src.tar.bz2:tigcc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C compiler for the TI89, 92, and 92+ calculators

USES=		bison tar:bzip2 gmake
NO_WRKSUBDIR=	yes

NO_STAGE=	yes
do-extract:
	@${MKDIR} ${WRKSRC}
	@${MKDIR} ${WRKSRC}/tigcc
	@${TAR} xjf ${DISTDIR}/tigcc_src.tar.bz2 -C ${WRKSRC}/tigcc/
	@${MKDIR} ${WRKSRC}/gnu
	@${TAR} xjf ${DISTDIR}/gcc-core-4.1-20060728.tar.bz2 -C ${WRKSRC}/gnu/
	@${TAR} xjf ${DISTDIR}/binutils-2.16.1.tar.bz2 -C ${WRKSRC}/gnu/

post-patch:
	@cd ${WRKSRC}/gnu/binutils-2.16.1; ${PATCH} -s -p1 < ${WRKSRC}/tigcc/sources/gcc/gas-2.16-tigcc-patch.diff
	@cd ${WRKSRC}/gnu/gcc-4.1-20060728; ${PATCH} -s -p1 < ${WRKSRC}/tigcc/sources/gcc/gcc-4.1-tigcc-patch.diff
	@cd ${WRKSRC}/gnu/gcc-4.1-20060728/gcc; ${ECHO} "echo all:" > mklibgcc.in

do-build:
	@${ECHO} Building GNU AS
	@${MKDIR} ${WRKSRC}/gnu/binutils_build
	@cd ${WRKSRC}/gnu/binutils_build; \
	 ${WRKSRC}/gnu/binutils-2.16.1/configure --disable-serial-configure --target=m68k-coff --disable-shared --enable-static --disable-multilib --disable-nls --disable-win32-registry
	@cd ${WRKSRC}/gnu/binutils_build; ${GMAKE}

	@${ECHO} Building the GNU C COMPILER
	@${MKDIR} ${WRKSRC}/gnu/gcc_build
	@cd ${WRKSRC}/gnu/gcc_build; \
	 ${WRKSRC}/gnu/gcc-4.1-20060728/configure --target=m68k-coff --with-gnu-as --disable-nls --disable-multilib --disable-shared --enable-static --disable-threads --disable-win32-registry --disable-checking --disable-werror --disable-pch --disable-mudflap --disable-libssp
	@cd ${WRKSRC}/gnu/gcc_build; ${GMAKE}

	@${ECHO} Building A68K
	@cd ${WRKSRC}/tigcc/sources/a68k; ${GMAKE}

	@${ECHO} Building LD-TIGCC
	@cd ${WRKSRC}/tigcc/sources/ld-tigcc; ${GMAKE}

	@${ECHO} Building PATCHER
	@cd ${WRKSRC}/tigcc/sources/patcher/src; ${GMAKE}

	@${ECHO} Building the ExePack support from the TIGCC Tools Suite
	@cd ${WRKSRC}/tigcc/sources/ttpack; ${CC} ${CFLAGS} -o ttpack ttpack.c
	@cd ${WRKSRC}/tigcc/sources/ttpack; ${CC} ${CFLAGS} -o ttbin2oth ttbin2oth.c

	@${ECHO} Building TIGCC
	@cd ${WRKSRC}/tigcc/sources/tigcc/src; ${GMAKE}

	@${ECHO} Building TPRBUILDER
	@cd ${WRKSRC}/tigcc/sources/tprbuilder/src; ${GMAKE}

do-install:
	@${MKDIR} ${PREFIX}/tigcc
	@${MKDIR} ${PREFIX}/tigcc/bin

	@${ECHO} Installing GNU AS
	@${INSTALL_PROGRAM} ${WRKSRC}/gnu/binutils_build/gas/as-new ${PREFIX}/tigcc/bin/as

	@${ECHO} Installing the GNU C Compiler
	@${INSTALL_PROGRAM} ${WRKSRC}/gnu/gcc_build/gcc/cc1 ${PREFIX}/tigcc/bin/cc1
	@${INSTALL_PROGRAM} ${WRKSRC}/gnu/gcc_build/gcc/xgcc ${PREFIX}/tigcc/bin/gcc

	@${ECHO} Installing A68K
	@${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/a68k/A68k ${PREFIX}/tigcc/bin/a68k

	@${ECHO} Installing LD-TIGCC
	@${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/ld-tigcc/ld-tigcc ${PREFIX}/tigcc/bin/ld-tigcc
	@${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/ld-tigcc/ar-tigcc ${PREFIX}/tigcc/bin/ar-tigcc

	@${ECHO} Installing PATCHER
	@${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/patcher/src/patcher ${PREFIX}/tigcc/bin/patcher

	@${ECHO} Installing the ExePack support from the TIGCC Tools Suite
	@${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/ttpack/ttpack ${PREFIX}/tigcc/bin/ttpack
	@${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/ttpack/ttbin2oth ${PREFIX}/tigcc/bin/ttbin2oth

	@${ECHO} Installing TIGCC
	@${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/tigcc/src/tigcc ${PREFIX}/tigcc/bin/tigcc

	@${ECHO} Installing TPRBUILDER
	@${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/tprbuilder/src/tprbuilder ${PREFIX}/tigcc/bin/tprbuilder

	@${ECHO} Installing TIGCCLIB
	@${CP} -R ${WRKSRC}/tigcc/tigcclib/include ${PREFIX}/tigcc/
	@${LN} -s ./os.h ${PREFIX}/tigcc/include/asm/OS.h
	@${CP} -R ${WRKSRC}/tigcc/tigcclib/lib ${PREFIX}/tigcc/

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO} Installing the TIGCC documentation
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/tigcc; ${CP} AUTHORS BUGS CHANGELOG COPYING DIRECTORIES HOWTO INSTALL README README.linux README.osX ${DOCSDIR}/
	@${MKDIR} ${DOCSDIR}/a68k
	@cd ${WRKSRC}/tigcc/sources/a68k; ${CP} Bugs.txt Doc.txt History.txt ToDo.txt ${DOCSDIR}/a68k/
	@${MKDIR} ${DOCSDIR}/tigcc
	@cd ${WRKSRC}/tigcc; ${CP} AUTHORS  COPYING  CHANGELOG  README ${DOCSDIR}/tigcc/
	@${MKDIR} ${DOCSDIR}/tprbuilder
	@cd ${WRKSRC}/tigcc/sources/tprbuilder; ${CP} AUTHORS  COPYING  ChangeLog  README ${DOCSDIR}/tprbuilder/
	@${MKDIR} ${DOCSDIR}/patcher
	@cd ${WRKSRC}/tigcc/sources/patcher; ${CP} AUTHORS  COPYING  ChangeLog  README ${DOCSDIR}/patcher/
	@${CP} -R ${WRKSRC}/tigcc/tigcclib/doc/html ${DOCSDIR}/
	@${LN} -s ./html ${DOCSDIR}/tigcclib
	@${CP} ${WRKSRC}/tigcc/tigcclib/doc/converter/tigccdoc ${PREFIX}/tigcc/bin/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} ${WRKSRC}/tigcc/tigcclib/examples/* ${EXAMPLESDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
