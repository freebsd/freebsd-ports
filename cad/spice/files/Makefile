
all:
	util/build FreeBSD default

install:
	util/build FreeBSD install 
	gzip < man/man5/mfbcap.5 > ${PREFIX}/man/man5/mfbcap.5.gz
	gzip < man/man1/sconvert.1 > ${PREFIX}/man/man1/sconvert.1.gz
	gzip < man/man1/nutmeg.1 > ${PREFIX}/man/man1/nutmeg.1.gz
	gzip < man/man1/spice.1 > ${PREFIX}/man/man1/spice.1.gz
	gzip < man/man3/mfb.3 > ${PREFIX}/man/man3/mfb.3.gz
