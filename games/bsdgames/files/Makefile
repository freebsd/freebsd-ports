# $FreeBSD$
.include "Makefile.inc"

GAMES=	adventure arithmetic atc backgammon battlestar bs canfield cribbage \
	fish hack hangman larn mille phantasia piano pig quiz robots rogue \
	sail snake trek worm wump
all:	${GAMES}
.for I in ${GAMES}
	cd ${I} && make depend && make all
.endfor

install: ${GAMES}
	mtree -deU -f var.mtree -p ${VARDIR}
	mtree -deU -f share.mtree -p ${SHAREDIR}
.for I in ${GAMES}
	cd ${I} && make install
.endfor

clean:	${GAMES}
.for I in ${GAMES}
	cd ${I} && make clean
.endfor

extract: ${GAMES}

.for I in ${GAMES}
${I}:
	cvs -d `pwd`/cvs get ${I}
.endfor

commit:
.for I in ${GAMES}
	cvs -d `pwd`/cvs commit -F ./commitmsg ${I}
.endfor

distclean:
	rm -rf ${GAMES}
