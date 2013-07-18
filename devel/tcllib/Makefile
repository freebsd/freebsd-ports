# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	tcllib
PORTVERSION=	1.15
PORTREVISION=	2
CATEGORIES=	devel tcl
MASTER_SITES=	SF

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	A collection of utility modules for Tcl

OPTIONS_DEFINE=	DOCS MANPAGES

USE_TCL=	84+

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_tclsh="${TCLSH}"
ALL_TARGET=	all
MAKE_ENV+=	LANG=C
PORTDOCS=	*

INSTALL_ARGS=	-pkgs -pkg-path ${PREFIX}/lib/tcllib \
		-apps -app-path ${PREFIX}/bin \
		-no-wait -no-gui -no-examples

.include <bsd.port.options.mk>

#
# Man pages
#
.if ${PORT_OPTIONS:MMANPAGES}
ALL_TARGET+=	nroff-doc
INSTALL_ARGS+=	-nroff-path ${MANPREFIX}/man/mann
.include "Makefile.man"
.else
INSTALL_ARGS+=	-no-nroff
.endif

#
# HTML documentation
#
.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	html-doc
INSTALL_ARGS+=	-html-path ${DOCSDIR}
.else
INSTALL_ARGS+=	-no-html
.endif

post-patch:
#
# 	Ensure, the detailed output of vendors' self-tests is
# 	available in addition to the pretty progress report:
#
	${REINPLACE_CMD} -e 's,test run,test run -l testlog,' \
		-e 's,$$(libdir)/@PACKAGE@@VERSION@,$$(libdir)/@PACKAGE@,' \
		${WRKSRC}/Makefile.in
	${FIND} ${WRKSRC}/apps -type f ! -name "*.man" | ${XARGS} \
	   ${REINPLACE_CMD} -e 's,exec tclsh,exec ${TCLSH},'
#
# 	patch(1) adds a newline at eof, so we need to remove it here
#
	${AWK} 'NR > 1 { print h } { h = $$0 } END { ORS = ""; print h }' \
	   ${WRKSRC}/modules/doctools/tests/text/04 > ${WRKSRC}/modules/doctools/tests/text/04.new
	${MV} ${WRKSRC}/modules/doctools/tests/text/04.new ${WRKSRC}/modules/doctools/tests/text/04
#
#	 .orig files confuse the pt module test suite and eventually get
#	 installed
#
	${FIND} ${WRKSRC} -name "*.orig" -delete
#
#	man pages have the .tcllib suffix, so there's no need to have a
#	tcllib_ prefix too
#
	for man in `${FIND} ${WRKSRC} -name "tcllib_*.man"`; do \
	    ${MV} $$man `echo $$man | ${SED} -e 's|tcllib_||'`; \
	done

do-install:
	cd ${WRKSRC} && ${TCLSH} ./installer.tcl ${INSTALL_ARGS}

regression-test: build
	cd ${WRKSRC} && ${SETENV} LANG=C LC_ALL=C DISPLAY= ${MAKE} test

.include <bsd.port.mk>
