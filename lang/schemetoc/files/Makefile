# Makefile for FreeBSD Scheme-to-C port

MAN_DIR = ${PREFIX}/man/man1
BIN_DIR = ${PREFIX}/bin
LIB_DIR = ${PREFIX}/lib
SCHEME_DIR = ${LIB_DIR}/schemetoc

all:
	make -f makefile forFREEBSD
	(cd FREEBSD;make port)
	(cd FREEBSD/cdecl; make all)
	(cd FREEBSD/xlib; make all)

install:
	mkdir -p ${SCHEME_DIR}/doc
	(cd FREEBSD/scrt; make "LIBDIR = ${LIB_DIR}" \
			       "BINDIR = ${BIN_DIR}" install)
	(cd FREEBSD/scsc; make "LIBDIR = ${LIB_DIR}" \
	                       "BINDIR = ${BIN_DIR}" install)
	(cd FREEBSD/xlib; make "LIBDIR = ${LIB_DIR}" \
                               "BINDIR = ${BIN_DIR}" install)
	(cd doc; install -c -m 444 index.psf \
				   embedded.psf \
			  	   intro.psf \
				   r4rs.psf \
		                   smithnotes.psf \
			           ${SCHEME_DIR}/doc)
	cp test/test51.sc ${SCHEME_DIR}/doc/test.sc
	cp xlib/hello.sc ${SCHEME_DIR}/doc
	cp xlib/puzzle.sc ${SCHEME_DIR}/doc
	cp README.FreeBSD ${SCHEME_DIR}/doc
	cp doc/scc.l ${MAN_DIR}/scc.1
	cp doc/sci.l ${MAN_DIR}/sci.1
	gzip -f ${MAN_DIR}/sci.1 ${MAN_DIR}/scc.1
	chmod 444 ${LIB_DIR}/libsc.so.1.0 ${LIB_DIR}/libscxl.so.1.0
	chown -R bin:bin ${SCHEME_DIR}
	strip ${BIN_DIR}/sccomp ${BIN_DIR}/sci ${BIN_DIR}/scixl
