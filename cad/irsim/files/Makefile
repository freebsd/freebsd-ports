CFLAGS = -O2 -USYS_V -UNO_SIGIO -DPOWER_EST -DUSER_SUBCKT -I${X11BASE}/include -L${X11BASE}/lib

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

	mkdir -p -m 555 ${PREFIX}/lib/irsim
	install -c -o bin -g bin -m 444 calibrate_hspice/scmos100.prm ${PREFIX}/lib/irsim
	install -c -o bin -g bin -m 444 calibrate_hspice/scmos30.prm ${PREFIX}/lib/irsim
	install -c -o bin -g bin -m 444 calibrate_hspice/scmos35.prm ${PREFIX}/lib/irsim
	install -c -o bin -g bin -m 444 calibrate_hspice/scmos60.prm ${PREFIX}/lib/irsim
	install -c -o bin -g bin -m 444 calibrate_hspice/scmos50_3v.prm ${PREFIX}/lib/irsim
	install -c -o bin -g bin -m 444 calibrate_hspice/scmos50_5v.prm ${PREFIX}/lib/irsim
	install -c -o bin -g bin -m 444 calibrate_spice3/scmos1_6um.prm ${PREFIX}/lib/irsim
	install -c -o bin -g bin -m 444 calibrate_spice3/scmos2um.prm ${PREFIX}/lib/irsim

clean:
	cd src/utils; make clean 
	cd src/irsim; make clean 
	cd src/ana11; make clean 
	cd src/fsim; make clean 

