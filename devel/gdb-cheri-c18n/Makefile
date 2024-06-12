PORTNAME=	gdb-cheri-c18n
PORTVERSION=	${GDB_RELEASE}.d${SNAPDATE}

COMMENT?=	GNU Project Debugger with support for the Arm Morello architecture and library compartmentalization

VER=		-cheri-c18n

OPTIONS_EXCLUDE=GDB_LINK KGDB

DATADIR?=	${PREFIX}/share/gdb-cheri-c18n

CONFIGURE_ARGS=	--with-gdb-datadir=${LOCALBASE}/share/gdb-cheri-c18n

FILESDIR=	${.CURDIR}/../gdb-cheri/files

SLAVE_PORT=	${PORTNAME}
.include "${.CURDIR}/../gdb-cheri/Makefile"
