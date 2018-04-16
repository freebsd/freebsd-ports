
# Use ?= to allow overriding from the env or command-line, e.g.
#
#	make CXXFLAGS="-O3 -fPIC" install
#
# Package managers will override many of these variables automatically, so
# this is aimed at making it easy to create packages (Debian packages,
# FreeBSD ports, MacPorts, pkgsrc, etc.)

CXX ?=		c++
CXXFLAGS ?=	-O3
DESTDIR ?=	stage
PREFIX ?=	/usr/local
STRIP ?=	strip
INSTALL ?=	install -c
MKDIR ?=	mkdir -p
AR ?=		ar

# Required flags that we shouldn't override
# Must be compiler-independent
CXXFLAGS +=	-D_FILE_OFFSET_BITS=64

BIN =	fastahack
LIB =	libfastahack.a
OBJS =	Fasta.o split.o disorder.o
MAIN =	FastaHack.o

all:	$(BIN) $(LIB)

$(BIN): $(OBJS) $(MAIN)
	$(CXX) $(CXXFLAGS) $(OBJS) $(MAIN) -o $(BIN)

$(LIB): $(OBJS)
	${AR} -rs $(LIB) $(OBJS)

FastaHack.o: Fasta.h FastaHack.cpp
	$(CXX) $(CXXFLAGS) -c FastaHack.cpp

Fasta.o: Fasta.h Fasta.cpp
	$(CXX) $(CXXFLAGS) -c Fasta.cpp

split.o: split.h split.cpp
	$(CXX) $(CXXFLAGS) -c split.cpp

disorder.o: disorder.c disorder.h
	$(CXX) $(CXXFLAGS) -c disorder.c

install: all
	$(MKDIR) $(DESTDIR)$(PREFIX)/bin
	$(MKDIR) $(DESTDIR)$(PREFIX)/include/fastahack
	$(MKDIR) $(DESTDIR)$(PREFIX)/lib
	$(INSTALL) $(BIN) $(DESTDIR)$(PREFIX)/bin
	$(INSTALL) *.h $(DESTDIR)$(PREFIX)/include/fastahack
	$(INSTALL) $(LIB) $(DESTDIR)$(PREFIX)/lib

install-strip: install
	$(STRIP) $(DESTDIR)$(PREFIX)/bin/$(BIN)

clean:
	rm -rf $(BIN) $(LIB) $(OBJS) $(DESTDIR)

.PHONY: clean
