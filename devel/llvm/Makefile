PORTNAME=	llvm
PORTVERSION=	${LLVM_MAJOR}
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	devel lang
MASTER_SITES=	# not applicable
DISTFILES=	# not applicable

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Meta-port for the default version of the LLVM Toolchain

# To the extent that anything in this port is copyrightable, it is the
# list of files in the chosen LLVM version which is under the ports
# collection license.
LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${.CURDIR}/../../COPYRIGHT

RUN_DEPENDS=	bugpoint${LLVM_SUFFIX}:devel/llvm${LLVM_SUFFIX}

OPTIONS_DEFINE=		CLANG EXTRAS LIT LLD LLDB
OPTIONS_DEFAULT=	CLANG EXTRAS LIT LLD LLDB

CLANG_DESC=	The clang compiler
EXTRAS_DESC=	Extra clang tools
LIT_DESC=	The lit and FileCheck test tools
LLD_DESC=	The LLVM linker
LLDB_DESC=	The LLVM debugger

CONFLICTS_INSTALL=	cling zapcc

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${COMMANDS:S|^|bin/|}

.include <bsd.port.options.mk>

LLVM_SUFFIX?=	${LLVM_DEFAULT}

.if ${LLVM_SUFFIX:M[789]0}
# Pre-LLVM 10 releases have a <Major><Minor> suffix
LLVM_MAJOR=${LLVM_SUFFIX:C/0$//}
.elif ${LLVM_SUFFIX:M[1-9][0-9]}
# LLVM 10 and later have a <Major> suffix
LLVM_MAJOR=${LLVM_SUFFIX}
.elif exists(${.CURDIR}/../llvm${LLVM_SUFFIX}/Makefile.snapshot)
# Try to get the version from the snapshot file for named
# suffixes.
.include "${.CURDIR}/../llvm${LLVM_SUFFIX}/Makefile.snapshot"
.else
.error Don't know how to get version for ${LLVM_SUFFIX}
.endif

.if ${LLVM_SUFFIX} == "-cheri" || ${LLVM_SUFFIX} == "-morello"
OPTIONS_EXCLUDE=	LLDB
.endif

.include "${.CURDIR}/../llvm${LLVM_SUFFIX}/Makefile.COMMANDS"

COMMANDS=	${LLVM_COMMANDS}
.if ${PORT_OPTIONS:MCLANG}
COMMANDS+=	${CLANG_COMMANDS}
.endif
.if ${PORT_OPTIONS:MEXTRAS}
COMMANDS+=	${EXTRAS_COMMANDS}
.endif
.if ${PORT_OPTIONS:MLIT}
COMMANDS+=	${LIT_COMMANDS}
.endif
.if ${PORT_OPTIONS:MLLD}
COMMANDS+=	${LLD_COMMANDS}
.endif
.if ${PORT_OPTIONS:MLLDB}
COMMANDS+=	${LLDB_COMMANDS}
.endif

do-install:
.for c in ${COMMANDS}
	    ${LN} -s ${c}${LLVM_SUFFIX} ${STAGEDIR}${PREFIX}/bin/${c}
.endfor

.include <bsd.port.mk>
