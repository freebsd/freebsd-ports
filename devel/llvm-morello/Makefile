# llvm-morello

LLVM_SUFFIX=	-morello

COMMENT=	LLVM and Clang with support the Arm Morello architecture

DISTINFO_FILE=	${.CURDIR}/distinfo
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GITLAB=	yes
GL_SITE=	https://git.morello-project.org
GL_ACCOUNT=	morello
GL_PROJECT=	llvm-project
GL_COMMIT=	${LLVM_COMMIT}

# Regularly tested targets as part of Android development
LLVM_TARGETS=	AArch64;ARM;BPF;X86

.include "${.CURDIR}/Makefile.snapshot"

MASTERDIR=	${.CURDIR}/../llvm-cheri

.include "${MASTERDIR}/Makefile"
