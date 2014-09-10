# $FreeBSD$

PORTNAME=	clang-cheri
PORTVERSION=	3.5.d20140815
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	C, Objective-C, and C++ compiler with CHERI CPU support

USES=		cmake:outsource compiler:c++11-lib ninja perl5 shebangfix \
		tar:bzip2
USE_PYTHON=	yes

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13

TRIPLE=		cheri-unknown-freebsd
SYSROOT=	${PREFIX}/sysroots/${TRIPLE}
LLVM_PREFIX=	${SYSROOT}/tools
TOOL_PREFIX=	${TRIPLE}-
CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_ARGS=	-DDEFAULT_SYSROOT=${SYSROOT} \
		-DLLVM_DEFAULT_TARGET_TRIPLE=${TRIPLE} \
		-DLLVM_ENABLE_CXX11=ON

SHEBANG_FILES=	\
		tools/clang/tools/clang-format/git-clang-format \
		tools/clang/tools/clang-format/clang-format-diff.py

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" \
		TOOL_PREFIX="${TOOL_PREFIX}" \
		TOOL_SUFFIX="${TOOL_SUFFIX}"

OPTIONS_DEFINE=	DOCS

PLIST_SUB+=	CLANG_RELEASE=${CLANG_RELEASE}

COMMANDS=	\
		bugpoint \
		clang \
		clang++ \
		clang-3.5 \
		clang-check \
		clang-cl \
		clang-cpp \
		clang-format \
		git-clang-format \
		llc \
		lldb \
		lldb-3.5 \
		lldb-gdbserver \
		lldb-gdbserver-3.5 \
		lldb-platform \
		lldb-platform-3.5 \
		lli \
		lli-child-target \
		llvm-ar \
		llvm-as \
		llvm-bcanalyzer \
		llvm-c-test \
		llvm-config \
		llvm-cov \
		llvm-diff \
		llvm-dis \
		llvm-dwarfdump \
		llvm-extract \
		llvm-link \
		llvm-lto \
		llvm-mc \
		llvm-mcmarkup \
		llvm-nm \
		llvm-objdump \
		llvm-readobj \
		llvm-rtdyld \
		llvm-size \
		llvm-stress \
		llvm-symbolizer \
		llvm-tblgen \
		macho-dump \
		opt
FIRST_COMMAND=	${COMMANDS:C/^/XXXX/1:MXXXX*:C/^XXXX//}

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "gcc"
BROKEN=	build errors when C++11 compiler is gcc
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+= svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export --force https://github.com/CTSRD-CHERI/llvm/trunk ${WRKSRC}
	svn export --force https://github.com/CTSRD-CHERI/clang/trunk \
	    ${WRKSRC}/tools/clang
	svn export --force https://github.com/CTSRD-CHERI/lldb/trunk \
	    ${WRKSRC}/tools/lldb
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == brooks || ${USER} == bed22
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    brooks@freefall.freebsd.org:public_distfiles/
.endif
.endif

post-patch:
	${REINPLACE_CMD} -e 's|\(PROJ_docsdir.*:=\).*$$|\1${DOCSDIR}|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|\(PROJ_mandir.*:=\).*$$|\1${MANPREFIX}/man|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' \
	    ${WRKSRC}/tools/clang/lib/Frontend/InitHeaderSearch.cpp

post-install:
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/clang \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/clang-cpp
	${INSTALL_SCRIPT} ${WRKDIR}/llvm-wrapper.sh \
	    ${STAGEDIR}${PREFIX}/bin/${TOOL_PREFIX}${FIRST_COMMAND}
.for command in ${COMMANDS:C/^/XXXX/1:NXXXX*}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${TOOL_PREFIX}${FIRST_COMMAND} \
	    ${STAGEDIR}${PREFIX}/bin/${TOOL_PREFIX}${command}
.endfor

build-plist:
	${RM} -f ${PLIST}
	${MAKE} makeplist | \
	    ${GREP} -v /you/have/to/check/what/makeplist/gives/you | \
	    ${SED} -e 's/%%PERL_ARCH%%/${PERL_ARCH}/' >> ${PLIST}

.include <bsd.port.post.mk>
