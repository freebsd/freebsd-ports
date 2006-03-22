# Makefile for Doug Lea's malloc
#
# (largely based on Mark Moreas' Makefile)
#
# Renamed dlmalloc
#
#  A version of malloc/free/realloc written by Doug Lea and released to the 
#  public domain. 
#
#  preliminary VERSION 2.8.3
#
#  working version; unreleased.
#
# $FreeBSD$
#

VER=2.8.3

LIBDIR=${PREFIX}/lib
INCDIR=${PREFIX}/include/dlmalloc

# for the shared lib stuff
.if ${PORTOBJFORMAT} == "elf"
VERSION=${VER:R:R}
.else
VERSION=${VER:R}
.endif

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
.if ${PORTOBJFORMAT} == "elf"
	ld -Bshareable -soname $(LIBSMALLOC) -o $(LIBSMALLOC) $(SOBJS) 
.else
	ld -Bshareable -o $(LIBSMALLOC) $(SOBJS) 
.endif

clean:
	-rm -f *.o \#* *~ *.core a.out gmon.out mon.out onefile.c *.sL prof.out

install:
	install -c -m 644 ${LIBMALLOC} $(LIBDIR)
	-$(RANLIB) $(LIBDIR)/${LIBMALLOC}
	install -c -m 444 ${LIBSMALLOC} $(LIBDIR)
	ln -sf ${LIBSMALLOC} $(LIBDIR)/libdlmalloc.so
	mkdir -p ${INCDIR}
	install -c -m 444 malloc-${VER}.h ${INCDIR}/malloc.h

$(OBJS): $(SRCS)
$(SOBJS): $(SRCS)
