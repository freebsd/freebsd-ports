CFLAGS = -USYS_V -UNO_SIGIO -DULTRIX_VERSION=4 -O2 -m486

all:
	@(cd src/utils; make)
	@(cd src/irsim; make SYSF="${CFLAGS}")
	@(cd src/fsim; make SYSF="${CFLAGS}")
	@(cd src/other/h2a; make SYSF="${CFLAGS}")
	@(cd src/other/inet2sim; make SYSF="${CFLAGS}")

install:
	install -cs -o bin -g bin -m 555 src/irsim/irsim ${PREFIX}/bin
	install -cs -o bin -g bin -m 555 src/fsim/ifsim ${PREFIX}/bin
	install -cs -o bin -g bin -m 555 src/other/h2a/h2a ${PREFIX}/bin
	install -cs -o bin -g bin -m 555 src/other/inet2sim/inet2sim ${PREFIX}/bin
	install -c -o bin -g bin -m 444 man/irsim.1 ${PREFIX}/man/man1
	install -c -o bin -g bin -m 444 man/irsim-analyzer.3 ${PREFIX}/man/man3
	install -c -o bin -g bin -m 444 man/netchange.5 ${PREFIX}/man/man5
	install -c -o bin -g bin -m 444 calibrate/scmos1_6um.prm ${PREFIX}/lib
	install -c -o bin -g bin -m 444 calibrate/scmos2um.prm ${PREFIX}/lib
