# $FreeBSD$

CSRCS= 	rig.c sdstr.c blocks.c an.c anfile.c extelt.c file.c file1.c vers.c \
	sdmms.c sdnmms.c slab.c litend.c tvset.c comp.c bitio.c tree.c macros.c \
	conv.c nbit.c man.c mgr.c testhdf.c tbv.c tvsfpack.c chunks.c tvattr.c \
    buffer.c

COBJS=	${CSRCS:S/.c/.o/g}

FSRCS= fortest.c fortestF.f forsupff.f forsupf.c \
	manf.f mgrf.f slabwf.f t24f.f tanf.f tanfilef.f tpf.f tr8f.f \
	tsdmmsf.f tsdnmmsf.f tsdnntf.f tsdntf.f tsdstrf.f tstubsf.f \
        tvsetf.f, tvattrf.f

FOBJS = fortestF.o forsupff.o forsupf.o \
	manf.o mgrf.o slabwf.o t24f.o tanf.o tanfilef.o tpf.o tr8f.o \
	tsdmmsf.o tsdnmmsf.o tsdnntf.o tsdntf.o tsdstrf.o tstubsf.o  \
        tvsetf.o tvattrf.o

#CFORSUPSRCS = forsupf.c

HDFLIB	 = ${.CURDIR}/../src
CFLAGS	+= -I${HDFLIB}
FFLAGS	+= ${CFLAGS} -Nn802 -Nx400

FTESTS = fortest fortestF

all: testhdf $(FTESTS) gentest

#CFORSUPOBJS = forsupf.o

TESTF = fortest.o

# directory used by extelt test.
TESTDIR = testdir

$(FOBJS): fortest.inc

test: atest-hdf

atest-hdf: testhdf $(FTESTS)
	-rm -f *.hdf 
	env LD_LIBRARY_PATH=${.CURDIR}/../src ./testhdf
	-rm -f *.hdf 
	env LD_LIBRARY_PATH=${.CURDIR}/../src ./fortest

testhdf: $(COBJS) $(HDFLIB)/libdf.so
	$(CC) -o testhdf $(COBJS) $(HDFLIB)/libdf.so -lm
	test -d $(TESTDIR) || mkdir $(TESTDIR)

fortestF: $(FOBJS) $(HDFLIB)/libdf.so
	$(FC) $(FFLAGS) -o $@ $(FOBJS) $(HDFLIB)/libdf.so -lm

fortest: $(HDFLIB)/libdf.so fortest.c $(CHDRS)
	$(CC) $(CFLAGS) -o fortest fortest.c $(HDFLIB)/libdf.so -lm

gentest: gentest.c $(HDFLIB)/libdf.so
	$(CC) $(CFLAGS) gentest.c -o gentest $(HDFLIB)/libdf.so -lm

clean: 
	-rm -f $(COBJS) testhdf $(FOBJS) $(FTESTS) \
	core *.hdf ptesthdf qtesthdf gentest *.o fortest.arg $(TESTDIR)/* \
	.depend

depend: 
	mkdep ${CFLAGS} ${CSRCS}

install:
