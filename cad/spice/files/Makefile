
all:
	util/build FreeBSD default

install:
	util/build FreeBSD install 
	chmod a+rx ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg \
	  ${PREFIX}/bin/sconvert ${PREFIX}/bin/help	\
	  ${PREFIX}/bin/proc2mod ${PREFIX}/bin/multidec
	strip ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg	\
	  ${PREFIX}/bin/sconvert ${PREFIX}/bin/help \
	  ${PREFIX}/bin/proc2mod ${PREFIX}/bin/multidec
	chmod -R a+rX ${PREFIX}/share/spice3
	install -c -m 644 -o bin -g bin man/man5/mfbcap.5 ${PREFIX}/man/man5/mfbcap.5
	install -c -m 644 -o bin -g bin man/man1/sconvert.1 ${PREFIX}/man/man1/sconvert.1
	install -c -m 644 -o bin -g bin man/man1/nutmeg.1 ${PREFIX}/man/man1/nutmeg.1
	install -c -m 644 -o bin -g bin man/man1/spice.1 ${PREFIX}/man/man1/spice.1
	install -c -m 644 -o bin -g bin man/man3/mfb.3 ${PREFIX}/man/man3/mfb.3
