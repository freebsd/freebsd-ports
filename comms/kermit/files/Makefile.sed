PROG=	kermit
CFLAGS+= -I${.CURDIR} -DBSD44 -DCK_CURSES -DTCPSOCKET \
	 -DNOCOTFMC -DTPUTSARGTYPE=int -DUSE_STRERROR -DFREEBSD3 \
	 -DUSE_UU_LOCK \
	 -funsigned-char
SRCS=   ckcmai.c ckucmd.c ckuusr.c ckuus2.c ckuus3.c ckuus4.c ckuus5.c \
        ckuus6.c ckuus7.c ckuusx.c ckuusy.c ckcpro.c ckcfns.c ckcfn2.c \
        ckcfn3.c ckuxla.c ckucns.c ckutio.c ckufio.c ckudia.c ckuscr.c \
        ckcnet.c ckusig.c ckclib.c ckctel.c ckcuni.c ckupty.c

BINDIR=%%PREFIX%%/bin
MANDIR=%%PREFIX%%/man/man

CLEANFILES+= ckcpro.c ckcwart.o wart kermit.1

DPADD=  ${LIBCURSES} ${LIBTERM}
LDADD=  -lncurses -lcrypt -lutil

.SUFFIXES: .w

.w.c:
	./wart ${.IMPSRC} ${.TARGET}

wart: ckwart.c
	$(CC) -o wart ${.CURDIR}/ckwart.c

ckcpro.c: ckcpro.w
ckcpro.c: wart

kermit.1: ckuker.nr
	cp ckuker.nr kermit.1

.include <bsd.prog.mk>
