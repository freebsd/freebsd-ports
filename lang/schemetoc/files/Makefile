# Makefile for FreeBSD Scheme-to-C port
#
# give this a CVS ID to satisfy commit_prep.pl --tg
# $FreeBSD$
#

MAN_DIR = ${PREFIX}/man/man1
BIN_DIR = ${PREFIX}/bin
LIB_DIR = ${PREFIX}/lib
SCHEME_DIR = ${LIB_DIR}/schemetoc

all:
	${MAKE} -f makefile forFREEBSD
	(cd FREEBSD; ${MAKE} port)
	(cd FREEBSD/cdecl; ${MAKE} all)
	(cd FREEBSD/xlib; ${MAKE} all)

install:
	mkdir -p ${SCHEME_DIR}/doc
	(cd FREEBSD/scrt; ${MAKE} "LIBDIR = ${LIB_DIR}" \
			       "BINDIR = ${BIN_DIR}" install)
	(cd FREEBSD/scsc; ${MAKE} "LIBDIR = ${LIB_DIR}" \
	                       "BINDIR = ${BIN_DIR}" install)
	(cd FREEBSD/xlib; ${MAKE} "LIBDIR = ${LIB_DIR}" \
                               "BINDIR = ${BIN_DIR}" install)
	(cd doc; ${BSD_INSTALL_DATA} index.psf \
				   embedded.psf \
			  	   intro.psf \
				   r4rs.psf \
		                   smithnotes.psf \
			           ${SCHEME_DIR}/doc)
	${BSD_INSTALL_DATA} test/test51.sc ${SCHEME_DIR}/doc/test.sc
	${BSD_INSTALL_DATA} xlib/hello.sc ${SCHEME_DIR}/doc
	${BSD_INSTALL_DATA} xlib/puzzle.sc ${SCHEME_DIR}/doc
	${BSD_INSTALL_DATA} README.FreeBSD ${SCHEME_DIR}/doc
	${BSD_INSTALL_DATA} doc/scc.l ${MAN_DIR}/scc.1
	${BSD_INSTALL_DATA} doc/sci.l ${MAN_DIR}/sci.1
