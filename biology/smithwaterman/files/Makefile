# =========================================
# MOSAIK Banded Smith-Waterman Makefile
# (c) 2009 Michael Stromberg & Wan-Ping Lee
# =========================================

# ----------------------------------
# define our source and object files
# ----------------------------------

SOURCES= smithwaterman.cpp BandedSmithWaterman.cpp SmithWatermanGotoh.cpp Repeats.cpp LeftAlign.cpp IndelAllele.cpp
OBJECTS= $(SOURCES:.cpp=.o) disorder.o
OBJECTS_NO_MAIN= disorder.o BandedSmithWaterman.o SmithWatermanGotoh.o Repeats.o LeftAlign.o IndelAllele.o

# ----------------
# compiler options
# ----------------

# Use ?= to allow overriding from the env or command-line, e.g.
#
#       make CXXFLAGS="-O3 -fPIC" install
#
# Package managers will override many of these variables automatically, so
# this is aimed at making it easy to create packages (Debian packages,
# FreeBSD ports, MacPorts, pkgsrc, etc.)

CXX ?=		c++
CXXFLAGS ?=	-O3
CXXFLAGS +=	-fPIC
DESTDIR ?=	stage
PREFIX ?=	/usr/local
STRIP ?=	strip
INSTALL ?=	install -c
MKDIR ?=	mkdir -p
AR ?=		ar
LN ?=		ln

LDFLAGS:=	-Wl,-s
BIN =		smithwaterman
LIB =		libsw.a
SOVERSION =	1
SLIB =		libsw.so.$(SOVERSION)

all: $(BIN) $(LIB) $(SLIB) sw.o

.PHONY: all

$(LIB): $(OBJECTS_NO_MAIN)
	$(AR) rs $@ $(OBJECTS_NO_MAIN)

$(SLIB): $(OBJECTS_NO_MAIN)
	$(CXX) -shared -Wl,-soname,$(SLIB) -o $(SLIB) $(OBJECTS_NO_MAIN)

sw.o:  $(OBJECTS_NO_MAIN)
	ld -r $^ -o sw.o -L.
	@#$(CXX) $(CFLAGS) -c -o smithwaterman.cpp $(OBJECTS_NO_MAIN) -I.

### @$(CXX) $(LDFLAGS) $(CFLAGS) -o $@ $^ -I.
$(BIN): $(OBJECTS)
	$(CXX) $(CFLAGS) $^ -I. -o $@

#smithwaterman: $(OBJECTS)
#	$(CXX) $(CXXFLAGS) -o $@ $< -I.

smithwaterman.o: smithwaterman.cpp disorder.o
	$(CXX) $(CXXFLAGS) -c -o $@ smithwaterman.cpp -I.

disorder.o: disorder.cpp disorder.h
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I.

BandedSmithWaterman.o: BandedSmithWaterman.cpp BandedSmithWaterman.h
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I.

SmithWatermanGotoh.o: SmithWatermanGotoh.cpp SmithWatermanGotoh.h disorder.o
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I.

Repeats.o: Repeats.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I.

LeftAlign.o: LeftAlign.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I.

IndelAllele.o: IndelAllele.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I.

install: all
	$(MKDIR) $(DESTDIR)$(PREFIX)/bin
	$(MKDIR) $(DESTDIR)$(PREFIX)/include/smithwaterman
	$(MKDIR) $(DESTDIR)$(PREFIX)/lib
	$(INSTALL) $(BIN) $(DESTDIR)$(PREFIX)/bin
	$(INSTALL) *.h $(DESTDIR)$(PREFIX)/include/smithwaterman
	$(INSTALL) $(LIB) $(SLIB) $(DESTDIR)$(PREFIX)/lib

install-strip: install
	$(STRIP) $(DESTDIR)$(PREFIX)/bin/$(BIN) $(DESTDIR)$(PREFIX)/lib/$(SLIB)

.PHONY: clean

clean:
	@echo "Cleaning up."
	@rm -rf $(BIN) $(LIB) $(SLIB) $(OBJECTS) $(DESTDIR)
