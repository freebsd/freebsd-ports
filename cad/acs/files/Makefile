# $FreeBSD$

all:
	cd src; \
	mkdir FreeBSD; \
	cat Make1 Make2.g++ Make3 Make.depend > FreeBSD/Makefile; \
	cd FreeBSD; \
	${MAKE} acs

install:
	@mkdir -p ${PREFIX}/share/acs
	@mkdir -p ${PREFIX}/share/doc/acs
	@mkdir -p ${PREFIX}/share/examples/acs
	${BSD_INSTALL_PROGRAM} src/FreeBSD/acs ${PREFIX}/bin
	${BSD_INSTALL_DATA} acs.rc ${PREFIX}/share/acs
	${BSD_INSTALL_DATA} doc/[a-z]* ${PREFIX}/share/doc/acs
	${BSD_INSTALL_DATA} man/man.pdf ${PREFIX}/share/doc/acs
	${BSD_INSTALL_DATA} examples/*.ckt examples/*.doc ${PREFIX}/share/examples/acs

