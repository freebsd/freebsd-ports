# New ports collection makefile for:	tigcc
# Date created:		15 February 2004
# Whom:			Ben Haga <tuximus@tuximus.mine.nu>
#
# $FreeBSD$
#

PORTNAME=	tigcc
PORTVERSION=	0.96.b6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=		${MASTER_SITE_GNU}:gcc,gas \
			http://tigcc.ticalc.org/linux/:tigcc
MASTER_SITE_SUBDIR=	gcc/gcc-4.0.2/:gcc \
			binutils/:gas
DISTFILES=		gcc-core-4.0.2.tar.bz2:gcc \
			binutils-2.16.1.tar.bz2:gas \
			tigcc_src.tar.bz2:tigcc

MAINTAINER=	walkingshadow@grummel.net
COMMENT=	C compiler for the TI89, 92, and 92+ calculators

USE_BZIP2=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${MKDIR} ${WRKSRC}/tigcc
	@${TAR} xjf ${DISTDIR}/tigcc_src.tar.bz2 -C ${WRKSRC}/tigcc/
	@${MKDIR} ${WRKSRC}/gnu
	@${TAR} xjf ${DISTDIR}/gcc-core-4.0.2.tar.bz2 -C ${WRKSRC}/gnu/
	@${TAR} xjf ${DISTDIR}/binutils-2.16.1.tar.bz2 -C ${WRKSRC}/gnu/

post-patch:
	@cd ${WRKSRC}/gnu/binutils-2.16.1; ${PATCH} -p1 < ${WRKSRC}/tigcc/sources/gcc/gas-2.16-tigcc-patch.diff
	@cd ${WRKSRC}/gnu/gcc-4.0.2; ${PATCH} -p1 < ${WRKSRC}/tigcc/sources/gcc/gcc-4.0-tigcc-patch.diff

do-build:
	@${ECHO} Building GNU AS
	@${MKDIR} ${WRKSRC}/gnu/binutils_build
	@cd ${WRKSRC}/gnu/binutils_build; \
	 ${WRKSRC}/gnu/binutils-2.16.1/configure --disable-serial-configure --target=m68k-coff --disable-shared --enable-static --disable-multilib --disable-nls --disable-win32-registry
	@cd ${WRKSRC}/gnu/binutils_build; ${GMAKE}

	@${ECHO} Building the GNU C COMPILER
	@${MKDIR} ${WRKSRC}/gnu/gcc_build
	@cd ${WRKSRC}/gnu/gcc_build; \
	 ${WRKSRC}/gnu/gcc-4.0.2/configure --target=m68k-coff --with-gnu-as --disable-nls --disable-multilib --disable-shared --enable-static --disable-threads --disable-win32-registry --disable-checking --disable-werror --disable-pch --disable-mudflap
	@cd ${WRKSRC}/gnu/gcc_build; ${GMAKE}

	@${ECHO} Building A68K
	@cd ${WRKSRC}/tigcc/sources/a68k; ${GMAKE}

	@${ECHO} Building tools required by TIGCC
	@cd ${WRKSRC}/tigcc/sources/ld-tigcc; ${GMAKE}
	@cd ${WRKSRC}/tigcc/sources/patcher/src; ${GMAKE}
	@cd ${WRKSRC}/tigcc/tt; ./makelinux.sh

	@${ECHO} Building TIGCC
	@cd ${WRKSRC}/tigcc/sources/tigcc/src; ${GMAKE}

	@${ECHO} Building TPRBUILDER
	@cd ${WRKSRC}/tigcc/sources/tprbuilder/src; ${GMAKE}

do-install:
	@${MKDIR} ${PREFIX}/tigcc
	@${MKDIR} ${PREFIX}/tigcc/bin

	@${ECHO} Installing GNU AS
	@${CP} ${WRKSRC}/gnu/binutils_build/gas/as-new ${PREFIX}/tigcc/bin/as

	@${ECHO} Installing the GNU C COMPILER
	@${CP} ${WRKSRC}/gnu/gcc_build/gcc/cc1 ${PREFIX}/tigcc/bin/cc1
	@${CP} ${WRKSRC}/gnu/gcc_build/gcc/xgcc ${PREFIX}/tigcc/bin/gcc

	@${ECHO} Installing A68K
	@${CP} ${WRKSRC}/tigcc/sources/a68k/A68k ${PREFIX}/tigcc/bin/a68k

	@${ECHO} Installing tools required by TIGCC
	@${CP} ${WRKSRC}/tigcc/sources/ld-tigcc/ld-tigcc ${PREFIX}/tigcc/bin/ld-tigcc
	@${CP} ${WRKSRC}/tigcc/sources/ld-tigcc/ar-tigcc ${PREFIX}/tigcc/bin/ar-tigcc
	@${CP} ${WRKSRC}/tigcc/sources/patcher/src/patcher ${PREFIX}/tigcc/bin/patcher
	@${CP} ${WRKSRC}/tigcc/tt/linuxbin/* ${PREFIX}/tigcc/bin/

	@${ECHO} Installing TIGCC
	@${CP} ${WRKSRC}/tigcc/sources/tigcc/src/tigcc ${PREFIX}/tigcc/bin/tigcc

	@${ECHO} Installing TPRBUILDER
	@${CP} ${WRKSRC}/tigcc/sources/tprbuilder/src/tprbuilder ${PREFIX}/tigcc/bin/tprbuilder

	@${ECHO} Installing TIGCCLIB
	@${MKDIR} ${PREFIX}/tigcc/include
	@${CP} -R ${WRKSRC}/tigcc/tigcclib/include ${PREFIX}/tigcc/
	@${LN} -s ${PREFIX}/tigcc/include/asm/os.h ${PREFIX}/tigcc/include/asm/OS.h
	@${MKDIR} ${PREFIX}/tigcc/lib
	@${CP} -R ${WRKSRC}/tigcc/tigcclib/lib ${PREFIX}/tigcc/
	@${MKDIR} ${PREFIX}/tigcc/examples
	@${CP} -R ${WRKSRC}/tigcc/tigcclib/examples ${PREFIX}/tigcc/

	@${ECHO} Installing the TIGCC documentation
	@${MKDIR} ${PREFIX}/tigcc/doc
	@cd ${WRKSRC}/tigcc; ${CP} AUTHORS BUGS CHANGELOG COPYING DIRECTORIES HOWTO INSTALL README README.linux README.osX ${PREFIX}/tigcc/doc/
	@${MKDIR} ${PREFIX}/tigcc/doc/a68k
	@cd ${WRKSRC}/tigcc/sources/a68k; ${CP} Bugs.txt Doc.txt History.txt ToDo.txt ${PREFIX}/tigcc/doc/a68k/
	@${MKDIR} ${PREFIX}/tigcc/doc/tigcc
	@cd ${WRKSRC}/tigcc; ${CP} AUTHORS  COPYING  CHANGELOG  README ${PREFIX}/tigcc/doc/tigcc/
	@${MKDIR} ${PREFIX}/tigcc/doc/tprbuilder
	@cd ${WRKSRC}/tigcc/sources/tprbuilder; ${CP} AUTHORS  COPYING  ChangeLog  README ${PREFIX}/tigcc/doc/tprbuilder/
	@${MKDIR} ${PREFIX}/tigcc/doc/patcher
	@cd ${WRKSRC}/tigcc/sources/patcher; ${CP} AUTHORS  COPYING  ChangeLog  README ${PREFIX}/tigcc/doc/patcher/
	@${CP} -R ${WRKSRC}/tigcc/tigcclib/doc/html ${PREFIX}/tigcc/doc/
	@${LN} -s ${PREFIX}/tigcc/doc/html ${PREFIX}/tigcc/doc/tigcclib
	@${CP} ${WRKSRC}/tigcc/tigcclib/doc/converter/tigccdoc ${PREFIX}/tigcc/bin/
	@${MKDIR} ${PREFIX}/tigcc/doc/tools
	@cd ${WRKSRC}/tigcc/tt; ${CP} history.txt linux_readme.txt  readme.txt  tooldocs.txt ${PREFIX}/tigcc/doc/tools/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
