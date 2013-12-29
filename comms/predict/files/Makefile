# $FreeBSD$

PREFIX=		%%PREFIX%%
STAGEDIR=	%%STAGEDIR%%

.ifndef	CC
CC	= 	-cc
.endif
.ifndef CPPFLAGS
CPPFLAGS =
.endif
.ifndef	CFLAGS
CFLAGS	=	-O2
.endif

default:	all
all:		predict vocalizer/vocalizer

LIBS += -lm -lncurses
predict:	predict.c predict.h
		${CC} ${CFLAGS} -o predict predict.c ${LIBS}

vocalizer/vocalizer:	vocalizer/vocalizer.c vocalizer/vocalizer.h	
		${CC} ${CFLAGS} -o vocalizer/vocalizer vocalizer/vocalizer.c ${LIBS}

clean:
	rm -f *.o predict *core *~ \#* *.txt vocalizer/vocalizer

install:
	mkdir -p ${STAGEDIR}${PREFIX}/share/predict/
	mkdir ${STAGEDIR}${PREFIX}/share/predict/default
	mkdir ${STAGEDIR}${PREFIX}/share/predict/vocalizer
	cp default/predict.db ${STAGEDIR}${PREFIX}/share/predict/default
	cp default/predict.qth ${STAGEDIR}${PREFIX}/share/predict/default
	cp default/predict.tle ${STAGEDIR}${PREFIX}/share/predict/default
	cp vocalizer/*.wav ${STAGEDIR}${PREFIX}/share/predict/vocalizer
	cp predict ${STAGEDIR}${PREFIX}/bin
	cp vocalizer/vocalizer ${STAGEDIR}${PREFIX}/bin

install.man:
	install docs/man/predict.1 ${STAGEDIR}${PREFIX}/man/man1

.PHONY:	clean build
