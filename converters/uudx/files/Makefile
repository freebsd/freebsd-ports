#
# makefile of uudx
#

CFLAGS += -DBSD=1 -DEUC=1 -DUTIME_EXIST -DMKDIR_HAS_MODE
PROGRAM = uudx
MANPAGE = uudx.1
MANDIR = ${PREFIX}/man/ja_JP.EUC/man1
SRC = uudx.c
OBJ = uudx.o

all: ${PROGRAM}

${PROGRAM}:     ${OBJ}
	${CC} ${CFLAGS} -o ${PROGRAM} ${OBJ}
	nkf -e ${MANPAGE} > ${MANPAGE}.tmp
	mv -f ${MANPAGE}.tmp ${MANPAGE}

install:        ${PROGRAM}
	${INSTALL} -c -s ${PROGRAM} ${PREFIX}/bin
	mkdir -p ${MANDIR}
	${INSTALL} -c ${MANPAGE} ${MANDIR}
