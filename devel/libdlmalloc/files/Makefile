# Makefile for Doug Lea's malloc
#
# (largely based on Mark Moreas' Makefile)
#
# Renamed dlmalloc
#
#  A version of malloc/free/realloc written by Doug Lea and released to the 
#  public domain. 
#
#  preliminary VERSION 2.8.4
#
#  working version; unreleased.
#
# $FreeBSD$
#

VER=2.8.6

LIBDIR=${PREFIX}/lib
INCDIR=${PREFIX}/include/dlmalloc

# for the shared lib stuff
VERSION=${VER:R:R}

LIBMALLOC=libdlmalloc.a
LIBSMALLOC=libdlmalloc.so.${VERSION}

SRCS = malloc-${VER}.c

OBJS = $(SRCS:.c=.o)
SOBJS = $(SRCS:.c=.so)

.SUFFIXES:
.SUFFIXES: .out .o .po .so .s .S .c .cc .cxx .m .C .f .y .l

.c.o:
	${CC} -c ${CFLAGS} $< -o $@

.c.so:
	${CC} -c -fpic ${CFLAGS} $< -o $@
	ld -x -r $@
	mv a.out $@

all: ${LIBMALLOC} ${LIBSMALLOC}

$(LIBMALLOC): $(OBJS)
	rm -f $(LIBMALLOC)
	$(AR) $(ARFLAGS) $(LIBMALLOC) $(OBJS)
	-$(RANLIB) $(LIBMALLOC)

$(LIBSMALLOC): $(SOBJS)
	rm -f $(LIBSMALLOC) 
	ld -Bshareable -soname $(LIBSMALLOC) -o $(LIBSMALLOC) $(SOBJS) 

clean:
	-rm -f *.o \#* *~ *.core a.out gmon.out mon.out onefile.c *.sL prof.out

install:
	install -c -m 644 ${LIBMALLOC} $(DESTDIR)$(LIBDIR)
	-$(RANLIB) $(DESTDIR)$(LIBDIR)/${LIBMALLOC}
	install -c -m 444 ${LIBSMALLOC} $(DESTDIR)$(LIBDIR)
	ln -sf ${LIBSMALLOC} $(DESTDIR)$(LIBDIR)/libdlmalloc.so
	mkdir -p $(DESTDIR)${INCDIR}
	install -c -m 444 malloc-${VER}.h $(DESTDIR)${INCDIR}/malloc.h

$(OBJS): $(SRCS)
$(SOBJS): $(SRCS)
