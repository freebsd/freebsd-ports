#
# $FreeBSD$
#

CCX =	c++

IDIR =	-I./bialib

OBJS =	bialib/mtstream.o \
	bialib/simplemodel.o \
	bialib/arithmetic.o \
	bialib/trivial.o \
	bialib/sufftree.o \
	bialib/exclude.o \
	bialib/rijndael.o \
	bicom/bicom.o

.cpp.o:
	${CCX} ${CXXFLAGS} ${IDIR} -c $< -o $*.o

all:	${OBJS}
	${CCX} ${CXXFLAGS} -o bicom/bicom ${OBJS}

clean:
	rm -f bicom/bicom bicom/*.o bialib/*.o core
