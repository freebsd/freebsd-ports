# Makefile for the ORTEP-III

TARGET= ortep3
SRC= ortep.f
OBJ= ortep.o
FFLAGS= -O2
LFLAGS=

all: ${OBJ}
	${FC} ${LFLAGS} -o ${TARGET} ${OBJ}

ortep.o: ortep.f
	${FC} ${FFLAGS} -c $<

clean:
	rm -f *.o ${TARGET}
