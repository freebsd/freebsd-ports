#
# $FreeBSD$
#

CXX ?=	c++

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
	${CXX} ${CXXFLAGS} ${IDIR} -o $@ -c $<

all:	${OBJS}
	${CXX} ${CXXFLAGS} -o bicom/bicom $>

clean:
	rm -f bicom/bicom bicom/*.o bialib/*.o core
