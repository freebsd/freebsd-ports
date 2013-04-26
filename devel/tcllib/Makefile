# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	tcllib
PORTVERSION=	1.15
CATEGORIES=	devel tcl
MASTER_SITES=	SF

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	A collection of utility modules for Tcl

USE_TCL=	84+

GNU_CONFIGURE=	yes
ALL_TARGET=	all
MAKE_ENV+=	LANG=C
PORTDOCS=	*

.include <bsd.port.options.mk>
.include "Makefile.man"

CONFIGURE_ENV+=	ac_cv_path_tclsh="${TCLSH}"

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

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${MAKE} html-doc
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

regression-test: build
	cd ${WRKSRC} && ${SETENV} LANG=C LC_ALL=C DISPLAY= ${MAKE} test

.include <bsd.port.mk>
