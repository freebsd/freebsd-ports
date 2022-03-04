# llvm-morello

LLVM_SUFFIX=	-morello

COMMENT=	LLVM and Clang with support the Arm Morello architecture

LLVM_MAJOR=	11
SNAPDATE=	20201020

DISTINFO_FILE=	${.CURDIR}/distinfo
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GITLAB=	yes
GL_SITE=	https://git.morello-project.org
GL_ACCOUNT=	morello
GL_PROJECT=	llvm-project
GL_COMMIT=	0619e74d198706df7361bc5739e7d7db38e3bc4f

# Regularly tested targets as part of Android development
LLVM_TARGETS=	AArch64;ARM;BPF;X86

MASTERDIR=	${.CURDIR}/../llvm-cheri

.include "${MASTERDIR}/Makefile"
