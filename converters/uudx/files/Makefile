#
# makefile of uudx
#
# $FreeBSD$

CFLAGS += -DBSD=1 -DEUC=1 -DUTIME_EXIST -DMKDIR_HAS_MODE
PROGRAM = uudx
MANPAGE = uudx.1
MANDIR = ${PREFIX}/man/ja/man1
SRC = uudx.c
OBJ = uudx.o

all: ${PROGRAM}

${PROGRAM}:     ${OBJ}
	${CC} ${CFLAGS} -o ${PROGRAM} ${OBJ}
	nkf -e ${MANPAGE} > ${MANPAGE}.tmp
	mv -f ${MANPAGE}.tmp ${MANPAGE}

install:        ${PROGRAM}
	${BSD_INSTALL_PROGRAM} ${PROGRAM} ${PREFIX}/bin
	${BSD_INSTALL_MAN} ${MANPAGE} ${MANDIR}
