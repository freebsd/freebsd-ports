# $FreeBSD$

PREFIX=		%%PREFIX%%
STAGEDIR=	%%STAGEDIR%%
CC=			%%CC%%
CFLAGS=		%%CFLAGS%%

default:	all
all:		predict vocalizer/vocalizer

LIBS = ${LDFLAGS} -pthread -lm -lncurses
predict:	predict.c predict.h
		${CC} ${CFLAGS} -o predict predict.c ${LIBS}

vocalizer/vocalizer:	vocalizer/vocalizer.c vocalizer/vocalizer.h
		${CC} ${CFLAGS} -I${LOCALBASE}/include -o vocalizer/vocalizer vocalizer/vocalizer.c -L${LOCALBASE}/lib ${LIBS} -lasound

clean:
	rm -f *.o predict *core *~ \#* *.txt vocalizer/vocalizer

install:
	mkdir -p ${STAGEDIR}${PREFIX}/share/predict/
	mkdir ${STAGEDIR}${PREFIX}/share/predict/default
	mkdir ${STAGEDIR}${PREFIX}/share/predict/vocalizer
	install -m 0644 default/predict.db ${STAGEDIR}${PREFIX}/share/predict/default
	install -m 0644 default/predict.qth ${STAGEDIR}${PREFIX}/share/predict/default
	install -m 0644 default/predict.tle ${STAGEDIR}${PREFIX}/share/predict/default
	install -m 0644 vocalizer/*.wav ${STAGEDIR}${PREFIX}/share/predict/vocalizer
	install predict ${STAGEDIR}${PREFIX}/bin
	strip ${STAGEDIR}${PREFIX}/bin/predict
	install vocalizer/vocalizer ${STAGEDIR}${PREFIX}/bin
	strip ${STAGEDIR}${PREFIX}/bin/vocalizer

install.man:
	install -m 0644  docs/man/predict.1 ${STAGEDIR}${PREFIX}/man/man1

.PHONY:	clean build
