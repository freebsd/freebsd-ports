PORTNAME?=	gdb-cheri
PORTVERSION?=	${GDB_RELEASE}.d${SNAPDATE}
PORTREVISION?=	0
CATEGORIES=	devel

USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_PROJECT=	gdb
GH_TAGNAME=	${GDB_COMMIT}

MAINTAINER=	konrad.witaszczyk@cl.cam.ac.uk
COMMENT?=	GNU Project Debugger with support for the Arm Morello architecture
WWW=		https://github.com/CTSRD-CHERI/gdb

NOT_FOR_ABIS=	purecap
NOT_FOR_ABIS_REASON_purecap=is not adapted for CheriABI yet

DATADIR?=	${PREFIX}/share/gdb

# devel/readline defines rl_completer_word_break_characters as const char *.
OPTIONS_DEFAULT+=BUNDLED_READLINE
OPTIONS_EXCLUDE+=PORT_READLINE

# CTSRD-CHERI/gdb does not include gdb.1.
GDB1_SRC=	${FILESDIR}/gdb.1
# CTSRD-CHERI/gdb does include kgdb.1.
KGDB1_SRC=	${WRKSRC}/gdb/doc/kgdb.1

.include "${.CURDIR}/Makefile.snapshot"

SLAVE_PORT?=	${PORTNAME}
GDBDIR=		${.CURDIR}/../gdb
DESCR=		${GDBDIR}/pkg-descr
PLIST=		${GDBDIR}/pkg-plist
PLIST_SUB+=	PYDISASSEMBLER="@comment "
.include "${GDBDIR}/Makefile"
