PORTNAME=	llvm
PORTVERSION=	${LLVM_DEFAULT}
PORTREVISION=	0
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

RUN_DEPENDS=	bugpoint${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

OPTIONS_DEFINE=		CLANG EXTRAS LIT LLD LLDB
OPTIONS_DEFAULT=	CLANG EXTRAS LIT LLD LLDB

CLANG_DESC=	The clang compiler
EXTRAS_DESC=	Extra clang tools
LIT_DESC=	The lit and FileCheck test tools
LLD_DESC=	The LLVM linker
LLDB_DESC=	The LLVM debugger

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${COMMANDS:S|^|bin/|}

.include <bsd.port.options.mk>
.include "${.CURDIR}/../llvm${LLVM_DEFAULT}/Makefile.COMMANDS"

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
	    ${LN} -s ${c}${LLVM_DEFAULT} ${STAGEDIR}${PREFIX}/bin/${c}
.endfor

.include <bsd.port.mk>
