# $FreeBSD$

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

all:		predict

SRCS = \
 predict.c

OBJS = ${SRCS:.c=.o}
LIBS += -lm -lncurses -o predict
#
#
HDRS = predict.h

predict:	${OBJS} ${HDRS}
		${CC} ${CFLAGS} -o $@ ${OBJS} ${LIBS}

.c.o:
	${CC} ${CPPFLAGS} ${CFLAGS} -c $<

,v.c:
	co $<

clean:
	rm -f *.o predict *core *~ \#* *.txt

install:
	echo INSTALL
	install	predict ${PREFIX}/bin

install.man:
	install docs/man/predict.1 ${PREFIX}/man/man1

.PHONY:	clean build
