PROG=	kermit
CFLAGS+= -I${.CURDIR} -DBSD44 -DCK_CURSES -DDYNAMIC -DTCPSOCKET \
	 -DNOCOTFMC -DSETREUID -DSAVEDUID -DNDSYSERRLIST
SRCS=   ckcmai.c ckucmd.c ckuusr.c ckuus2.c ckuus3.c ckuus4.c ckuus5.c \
        ckuus6.c ckuus7.c ckuusx.c ckuusy.c ckcpro.c ckcfns.c ckcfn2.c \
        ckcfn3.c ckuxla.c ckucon.c ckutio.c ckufio.c ckudia.c ckuscr.c \
        ckcnet.c

BINMODE=2555
BINGRP=dialer

BINDIR=%%PREFIX%%/bin
MANDIR=%%PREFIX%%/man/man

CLEANFILES+= ckcpro.c ckcwart.o wart

DPADD=  ${LIBCURSES} ${LIBTERM}
LDADD=  -lcurses -ltermcap

.SUFFIXES: .w

.w.c:
	./wart ${.IMPSRC} ${.TARGET}

wart: ckwart.c
	$(CC) -o wart ${.CURDIR}/ckwart.c

ckcpro.c: ckcpro.w
ckcpro.c: wart

.include <bsd.prog.mk>
