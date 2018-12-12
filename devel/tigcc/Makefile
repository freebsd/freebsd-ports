# Created by: Ben Haga <tuximus@tuximus.mine.nu>
# $FreeBSD$

PORTNAME=	tigcc
PORTVERSION=	0.96.b8
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=		GCC/snapshots/4.1-20060728:gcc \
			GNU/binutils:gas \
			http://tigcc.ticalc.org/linux/:tigcc
DISTFILES=		gcc-core-4.1-20060728.tar.bz2:gcc \
			binutils-2.16.1.tar.bz2:gas \
			tigcc_src.tar.bz2:tigcc

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	C compiler for the TI89, 92, and 92+ calculators

USES=		bison compiler:nestedfct gmake tar:bzip2
USE_CSTD=	gnu89
NO_WRKSUBDIR=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

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
	@${REINPLACE_CMD} -e 's/^CC[[:space:]]*=/CC ?=/' -e 's/^CFLAGS[[:space:]]*=/CFLAGS ?=/' \
		${WRKSRC}/tigcc/sources/a68k/Makefile ${WRKSRC}/tigcc/sources/ld-tigcc/Makefile \
		${WRKSRC}/tigcc/sources/patcher/src/Makefile ${WRKSRC}/tigcc/sources/tigcc/src/Makefile \
		${WRKSRC}/tigcc/sources/tprbuilder/src/Makefile

do-build:
	@${ECHO} Building GNU AS
	@${MKDIR} ${WRKSRC}/gnu/binutils_build
	@cd ${WRKSRC}/gnu/binutils_build; \
		${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
		${CONFIGURE_ENV} \
		${WRKSRC}/gnu/binutils-2.16.1/configure --disable-serial-configure --target=m68k-coff --disable-shared \
		--enable-static --disable-multilib --disable-nls --disable-win32-registry
	@cd ${WRKSRC}/gnu/binutils_build; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS}

	@${ECHO} Building the GNU C COMPILER
	@${MKDIR} ${WRKSRC}/gnu/gcc_build
	@cd ${WRKSRC}/gnu/gcc_build; \
		${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
		${CONFIGURE_ENV} \
		${WRKSRC}/gnu/gcc-4.1-20060728/configure --target=m68k-coff --with-gnu-as --disable-nls --disable-multilib \
		--disable-shared --enable-static --disable-threads --disable-win32-registry --disable-checking --disable-werror \
		--disable-pch --disable-mudflap --disable-libssp
	@cd ${WRKSRC}/gnu/gcc_build; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS}

	@${ECHO} Building A68K
	@cd ${WRKSRC}/tigcc/sources/a68k; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS}

	@${ECHO} Building LD-TIGCC
	@cd ${WRKSRC}/tigcc/sources/ld-tigcc; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS}

	@${ECHO} Building PATCHER
	@cd ${WRKSRC}/tigcc/sources/patcher/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS}

	@${ECHO} Building the ExePack support from the TIGCC Tools Suite
	@cd ${WRKSRC}/tigcc/sources/ttpack; ${CC} ${CFLAGS} -o ttpack ttpack.c
	@cd ${WRKSRC}/tigcc/sources/ttpack; ${CC} ${CFLAGS} -o ttbin2oth ttbin2oth.c

	@${ECHO} Building TIGCC
	@cd ${WRKSRC}/tigcc/sources/tigcc/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS}

	@${ECHO} Building TPRBUILDER
	@cd ${WRKSRC}/tigcc/sources/tprbuilder/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/tigcc
	@${MKDIR} ${STAGEDIR}${PREFIX}/tigcc/bin

	@${ECHO} Installing GNU AS
	${INSTALL_PROGRAM} ${WRKSRC}/gnu/binutils_build/gas/as-new ${STAGEDIR}${PREFIX}/tigcc/bin/as

	@${ECHO} Installing the GNU C Compiler
	${INSTALL_PROGRAM} ${WRKSRC}/gnu/gcc_build/gcc/cc1 ${STAGEDIR}${PREFIX}/tigcc/bin/cc1
	${INSTALL_PROGRAM} ${WRKSRC}/gnu/gcc_build/gcc/xgcc ${STAGEDIR}${PREFIX}/tigcc/bin/gcc

	@${ECHO} Installing A68K
	${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/a68k/A68k ${STAGEDIR}${PREFIX}/tigcc/bin/a68k

	@${ECHO} Installing LD-TIGCC
	${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/ld-tigcc/ld-tigcc ${STAGEDIR}${PREFIX}/tigcc/bin/ld-tigcc
	${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/ld-tigcc/ar-tigcc ${STAGEDIR}${PREFIX}/tigcc/bin/ar-tigcc

	@${ECHO} Installing PATCHER
	${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/patcher/src/patcher ${STAGEDIR}${PREFIX}/tigcc/bin/patcher

	@${ECHO} Installing the ExePack support from the TIGCC Tools Suite
	${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/ttpack/ttpack ${STAGEDIR}${PREFIX}/tigcc/bin/ttpack
	${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/ttpack/ttbin2oth ${STAGEDIR}${PREFIX}/tigcc/bin/ttbin2oth

	@${ECHO} Installing TIGCC
	${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/tigcc/src/tigcc ${STAGEDIR}${PREFIX}/tigcc/bin/tigcc

	@${ECHO} Installing TPRBUILDER
	${INSTALL_PROGRAM} ${WRKSRC}/tigcc/sources/tprbuilder/src/tprbuilder ${STAGEDIR}${PREFIX}/tigcc/bin/tprbuilder

	@${ECHO} Installing TIGCCLIB
	@${CP} -R ${WRKSRC}/tigcc/tigcclib/include ${STAGEDIR}${PREFIX}/tigcc/
	@${LN} -s ./os.h ${STAGEDIR}${PREFIX}/tigcc/include/asm/OS.h
	@${CP} -R ${WRKSRC}/tigcc/tigcclib/lib ${STAGEDIR}${PREFIX}/tigcc/

do-install-DOCS-on:
	@${ECHO} Installing the TIGCC documentation
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/tigcc; ${CP} AUTHORS BUGS CHANGELOG COPYING DIRECTORIES HOWTO INSTALL README README.linux README.osX ${STAGEDIR}${DOCSDIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/a68k
	@cd ${WRKSRC}/tigcc/sources/a68k; ${CP} Bugs.txt Doc.txt History.txt ToDo.txt ${STAGEDIR}${DOCSDIR}/a68k/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/tigcc
	@cd ${WRKSRC}/tigcc; ${CP} AUTHORS  COPYING  CHANGELOG  README ${STAGEDIR}${DOCSDIR}/tigcc/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/tprbuilder
	@cd ${WRKSRC}/tigcc/sources/tprbuilder; ${CP} AUTHORS COPYING ChangeLog README ${STAGEDIR}${DOCSDIR}/tprbuilder/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/patcher
	@cd ${WRKSRC}/tigcc/sources/patcher; ${CP} AUTHORS  COPYING  ChangeLog  README ${STAGEDIR}${DOCSDIR}/patcher/
	@${CP} -R ${WRKSRC}/tigcc/tigcclib/doc/html ${STAGEDIR}${DOCSDIR}/
	@${LN} -s ./html ${STAGEDIR}${DOCSDIR}/tigcclib
	@${CP} ${WRKSRC}/tigcc/tigcclib/doc/converter/tigccdoc ${STAGEDIR}${PREFIX}/tigcc/bin/

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${CP} ${WRKSRC}/tigcc/tigcclib/examples/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.pre.mk>

.if exists(/usr/lib/libstdc++.so)
CFLAGS+=	-fnested-functions
.endif

.include <bsd.port.post.mk>
