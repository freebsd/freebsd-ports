# Makefile for Doug Lea's malloc
#
# (largely based on Mark Moreas' Makefile)
#
# Renamed dlmalloc
#
#  A version of malloc/free/realloc written by Doug Lea and released to the 
#  public domain. 
#
#  preliminary VERSION 2.5.3b
#
#  working version; unreleased.
#

LIBDIR=${PREFIX}/lib

# for the shared lib stuff
VERSION=2.5

LIBMALLOC=libdlmalloc.a
LIBSMALLOC=libdlmalloc.so.${VERSION}

SRCS = malloc-2.5.3b.c

OBJS = malloc-2.5.3b.o
SOBJS = malloc-2.5.3b.so

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
	ld -Bshareable -o $(LIBSMALLOC) $(SOBJS) 

clean:
	-rm -f *.o \#* *~ *.core a.out gmon.out mon.out onefile.c *.sL prof.out

install:
	install -c -m 644 ${LIBMALLOC} $(LIBDIR)
	-$(RANLIB) $(LIBDIR)/${LIBMALLOC}
	install -c -m 555 ${LIBSMALLOC} $(LIBDIR)

malloc-2.5.3b.o:	malloc-2.5.3b.c
malloc-2.5.3b.so:	malloc-2.5.3b.c
