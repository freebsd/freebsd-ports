#
# makefile of uudx
#

CFLAGS += -DBSD=1 -DEUC=1 -DUTIME_EXIST -DMKDIR_HAS_MODE
PROGRAM = uudx
MANPAGE = uudx.1
MANDIR = ${PREFIX}/man/ja_JP.sjis/man1
SRC = uudx.c
OBJ = uudx.o

all: ${PROGRAM}

${PROGRAM}:     ${OBJ}
	${CC} ${CFLAGS} -o ${PROGRAM} ${OBJ}

install:        ${PROGRAM}
	${INSTALL} -c -s ${PROGRAM} ${PREFIX}/bin
	mkdir -p ${MANDIR}
	${INSTALL} -c ${MANPAGE} ${MANDIR}
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${MANDIR}/${MANPAGE}

.endif
