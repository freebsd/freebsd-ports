# $FreeBSD$

PREFIX?=	/usr/local

CC?=	gcc
CXX?=	g++
CFLAGS+=	-I. -O -Wimplicit -Wreturn-type -Wswitch \
		-Wcomment -Wformat -Wchar-subscripts \
		-Wparentheses -Wpointer-arith -Wcast-qual \
		-Woverloaded-virtual -static
CXXFLAGS+=	${CFLAGS} -Wno-deprecated
LIBS=	-lm -lstdc++
LDADD+=	${LIBS}

PROG=	gds2gdt gdt2gds

SRCS.gds2gdt=	sRemoveTrailingZeros.C get_field.c stoupper.c sfind.C \
	match_string.C sRemoveSpaces.C sRemoveWhiteSpace.C \
	mystrncpy.C gdsStream.C gds2gdt.C

.for P in ${PROG}
OBJS.${P}=	${SRCS.${P}:N*.h:R:S,$,.o,g}
.endfor

SRCS.gdt2gds=	sRemoveWhiteSpace.C sRemoveTrailingZeros.C \
		get_field.c stoupper.c sfind.C match_string.C \
		sRemoveSpaces.C mystrncpy.C gdsStream.C gdt2gds.C	

BSD_INSTALL_PROGRAM?=	install -s -m 555

all: ${PROG}

clean:
	rm -f *.o ${PROG}

install:
	${BSD_INSTALL_PROGRAM} ${PROG} ${PREFIX}/bin

.for P in ${PROG}
${P}: ${OBJS.${P}}
	${CC} ${CFLAGS} ${LDFLAGS} -o ${.TARGET} ${OBJS.${P}} ${LDADD}
.endfor

.for F in ${SRCS:M*.C}
${F:R:S,$,.o,g}: ${F}
	${CC} ${CFLAGS} -c -o ${.TARGET} ${F}
.endfor
.for F in ${SRCS:M*.c}
${F:R:S,$,.o,g}: ${F}
	${CXX} ${CXXFLAGS} -c -o ${.TARGET} ${F}
.endfor
