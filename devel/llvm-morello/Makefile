# llvm-morello

LLVM_SUFFIX=	-morello

COMMENT=	LLVM and Clang with support the Arm Morello architecture
WWW=		https://git.morello-project.org/morello/llvm-project

DISTINFO_FILE=	${.CURDIR}/distinfo
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GITLAB=	yes
GL_SITE=	https://git.morello-project.org
GL_ACCOUNT=	morello
GL_PROJECT=	llvm-project
GL_TAGNAME=	${LLVM_COMMIT}

# Regularly tested targets as part of Android development
LLVM_TARGETS=	AArch64;ARM;BPF;X86

MASTERDIR=	${.CURDIR}/../llvm-cheri

.include "${MASTERDIR}/Makefile"
