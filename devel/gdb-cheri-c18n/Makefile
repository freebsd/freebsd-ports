PORTNAME=	gdb-cheri-c18n
PORTVERSION=	${GDB_RELEASE}.d${SNAPDATE}

COMMENT?=	GNU Project Debugger with support for the Arm Morello architecture and library compartmentalization

VER=		-cheri-c18n

OPTIONS_EXCLUDE=GDB_LINK KGDB
# Exclude PYTHON not to conflict with gdb-cheri on libcxx-gdbpy.
OPTIONS_EXCLUDE+=PYTHON

DATADIR?=	${PREFIX}/share/gdb-cheri-c18n

# GDB 14.1 checks if gmp and mpfr headers exist in configure.
CONFIGURE_ARGS=	--disable-sim \
		--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE} \
		--with-gdb-datadir=${LOCALBASE}/share/gdb-cheri-c18n

FILESDIR=	${.CURDIR}/../gdb-cheri/files

SLAVE_PORT=	${PORTNAME}
.include "${.CURDIR}/../gdb-cheri/Makefile"
