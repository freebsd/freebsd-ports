# $FreeBSD$

CXXFLAGS+= -MMD `fltk-config --cxxflags` `sdl-config --cflags`
PREFIX	?= /usr/local
INSTALL_PROGRAM	?=	${INSTALL} -o root -g wheel -m 755

all: xmorse

m.cxx: m.fl
	fluid -c m.fl

xmorse: m.o Bargraph.o Codebox.o Cw.o Knob.o
	${CXX} -o$@ $> `fltk-config --ldflags` `sdl-config --libs`

install: xmorse
	${INSTALL_PROGRAM} xmorse ${PREFIX}/bin/xmorse

clean:
	-rm *.o
	-rm *.d
	-rm m.cxx m.h
	-rm xmorse
