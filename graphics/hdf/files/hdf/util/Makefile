# $FreeBSD$

UTILS	 = hdf24to8 hdfcomp hdfls hdfpack hdftopal hdftor8 paltohdf \
        r8tohdf ristosds  vmake vshow hdf8to24 hdf2jpeg jpeg2hdf fp2hdf \
	hdfunpac vcompat

all: ${UTILS} hdfed

HEOBJ = he_main.o he_cntrl.o he_disp.o he_file.o

#CFLAGS	+= -I${PREFIX}/include -I${.CURDIR}/../src/
CFLAGS	+=  -I${.CURDIR}/../src/
#LDFLAGS	+= -L${PREFIX}/lib -ljpeg -L${.CURDIR}/../src/ -ldf -lz
LDFLAGS	+= -L${.CURDIR}/../src/ -ldf

hdfed: he.h he_proto.h $(HEOBJ)
	$(CC) $(HEOBJ) $(LDFLAGS) -o hdfed

test: all fptest
	env LD_LIBRARY_PATH=${.CURDIR}/../src ./testutil.sh

clean:
	-rm -f *.o $(UTILS) hdfed fptest
	-rm -f o* ctx* cb* fptestf .depend

depend:
	mkdep ${CFLAGS} ${UTILS:S/$/.c/g} ${HEOBJ:S/.o/.c/g}

install: all
	install -c -s -o root -g wheel -m 555 ${UTILS} hdfed ${BINDIR}
