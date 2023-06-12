# llvm-morello-csa

LLVM_SUFFIX=	-morello-csa

MAINTAINER=	irina.dudina@ed.ac.uk
COMMENT=	Clang Static Analyzer for the Arm Morello architecture
WWW=		https://github.com/rems-project/llvm-project

DISTINFO_FILE=	${.CURDIR}/distinfo
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
FILESDIR=	${.CURDIR}/files

GH_PROJECT=	llvm-project
GH_ACCOUNT=	rems-project

MASTERDIR=	${.CURDIR}/../llvm-cheri

OPTIONS_EXCLUDE=	LLD LIT STATIC_LIBS DOCS XTOOLCHAIN
OPTIONS_SLAVE=		CLANG CSA

LLVM_TARGETS=	AArch64;ARM;BPF;X86

SUB_FILES=	csa-wrapper.sh

post-patch-CSA-on:
	@${REINPLACE_CMD} -e 's|%%LLVM_PREFIX%%|${LLVM_PREFIX}|g' \
		${WRKSRC}/clang/tools/scan-build/bin/scan-build

CSA_COMMANDS=	ccc-analyzer c++-analyzer
post-install-CSA-on:
.for c in ${CSA_COMMANDS}
	${INSTALL_SCRIPT} ${WRKDIR}/csa-wrapper.sh \
	    ${STAGEDIR}${PREFIX}/libexec/${c}
.endfor
	${INSTALL_SCRIPT} ${STAGEDIR}${LLVM_PREFIX}/bin/scan-build \
	    ${STAGEDIR}${PREFIX}/bin/${COMMAND_PREFIX}scan-build${LLVM_SUFFIX}

.include "${MASTERDIR}/Makefile"
