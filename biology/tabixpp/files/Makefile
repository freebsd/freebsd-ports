
# Use ?= to allow overriding from the env or command-line, e.g.
#
#       make CXXFLAGS="-O3 -fPIC" install
#
# Package managers will override many of these variables automatically, so
# this is aimed at making it easy to create packages (Debian packages,
# FreeBSD ports, MacPorts, pkgsrc, etc.)

CC ?=		cc
CXX ?= 		c++
CXXFLAGS ?=	-g -Wall -O2 #-m64 #-arch ppc
CXXFLAGS +=	-fPIC
INCLUDES ?=	-Ihtslib
HTS_HEADERS ?=	htslib/htslib/bgzf.h htslib/htslib/tbx.h
HTS_LIB ?=	htslib/libhts.a
LDFLAGS ?=	-Lhtslib
LDFLAGS +=	-L.

DESTDIR ?=	stage
PREFIX ?=	/usr/local
STRIP ?=	strip
INSTALL ?=	install -c
MKDIR ?=	mkdir -p
AR ?=		ar

DFLAGS =	-D_FILE_OFFSET_BITS=64 -D_USE_KNETFILE
BIN =		tabix++
LIB =		libtabix.a
SOVERSION =	1
SLIB =		libtabix.so.$(SOVERSION)
OBJS =		tabix.o
SUBDIRS =	.

.SUFFIXES:.c .o

.c.o:
	$(CC) -c $(CXXFLAGS) $(DFLAGS) $(INCLUDES) $< -o $@

all-recur lib-recur clean-recur cleanlocal-recur install-recur:
	@target=`echo $@ | sed s/-recur//`; \
	wdir=`pwd`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
		cd $$subdir; \
		$(MAKE) CC="$(CC)" DFLAGS="$(DFLAGS)" CXXFLAGS="$(CXXFLAGS)" \
			INCLUDES="$(INCLUDES)" LDFLAGS="$(LDFLAGS)" $$target \
			|| exit 1; \
		cd $$wdir; \
	done;

all:	$(BIN) $(LIB) $(SLIB)

tabix.o: $(HTS_HEADERS) tabix.cpp tabix.hpp
	$(CXX) $(CXXFLAGS) -c tabix.cpp $(INCLUDES)

htslib/libhts.a:
	cd htslib && $(MAKE) lib-static

$(LIB): $(OBJS)
	$(AR) rs $(LIB) $(OBJS)

$(SLIB): $(OBJS)
	$(CXX) -shared -Wl,-soname,$(SLIB) -o $(SLIB) $(OBJS)

tabix++: $(OBJS) main.cpp $(HTS_LIB)
	$(CXX) $(CXXFLAGS) -o $@ main.cpp $(OBJS) $(INCLUDES) $(LDFLAGS) \
		-lhts -lpthread -lm -lz

install: all
	$(MKDIR) $(DESTDIR)$(PREFIX)/bin
	$(MKDIR) $(DESTDIR)$(PREFIX)/include
	$(MKDIR) $(DESTDIR)$(PREFIX)/lib
	$(INSTALL) $(BIN) $(DESTDIR)$(PREFIX)/bin
	$(INSTALL) *.hpp $(DESTDIR)$(PREFIX)/include
	$(INSTALL) $(LIB) $(SLIB) $(DESTDIR)$(PREFIX)/lib

install-strip: install
	$(STRIP) $(DESTDIR)$(PREFIX)/bin/$(BIN) $(DESTDIR)$(PREFIX)/lib/$(SLIB)

cleanlocal:
	rm -rf $(BIN) $(LIB) $(SLIB) $(OBJS) $(DESTDIR)
	rm -fr gmon.out *.o a.out *.dSYM $(BIN) *~ *.a tabix.aux tabix.log \
		tabix.pdf *.class libtabix.*.dylib
	cd htslib && $(MAKE) clean

clean: cleanlocal-recur
