# New ports collection makefile for: 	tcllib
# Date created:				27 Apr 2000
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	tcllib
PORTVERSION=	1.14
CATEGORIES=	devel tcl
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A collection of utility modules for Tcl

USE_TCL_BUILD=	82+
USE_TCL_RUN=	${USE_TCL_BUILD}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all
MAKE_ENV+=	LANG=C

.include <bsd.port.pre.mk>
.include "Makefile.man"

CONFIGURE_ENV+=	ac_cv_path_tclsh="${TCLSH}"

post-patch:
	#
	# Ensure, the detailed output of vendors' self-tests is
	# available in addition to the pretty progress report:
	#
	${REINPLACE_CMD} -e 's,test run,test run -l testlog,' \
		-e 's,$$(libdir)/@PACKAGE@@VERSION@,$$(libdir)/@PACKAGE@,' \
		${WRKSRC}/Makefile.in
	${FIND} ${WRKSRC}/apps -type f ! -name "*.man" | ${XARGS} \
	   ${REINPLACE_CMD} -e 's,exec tclsh,exec ${TCLSH},'

RUNTEST=	${SETENV} LANG=C DISPLAY= ${MAKE} -C ${WRKSRC} test
MYID	!=	${ID} -u
.if ${MYID} == 0
RUNTEST:=	${SU_CMD:S/root/-m nobody/} "${RUNTEST}"
pre-build:
	#
	# Preparing to run the tests as `nobody'
	#
	${FIND} ${WRKSRC} -type d -o -name jpeg.test | ${XARGS} ${CHOWN} nobody
.endif

test:
	@if ! ${RUNTEST};	\
	then	\
		${AWK} '$$NF == "FAILED" { echo = 1 }	\
			echo { if ($$NF == "start") echo = 0; else print }'	\
				${WRKSRC}/testlog.log;	\
		${CAT} ${WRKSRC}/testlog.failures;	\
		${UNAME} -a;	\
		${ECHO_MSG} Please, analyze and report the test failures;	\
		${ECHO_MSG} Be sure to use the latest available microversion;	\
		${ECHO_MSG} of TCL-${TCL_VER}, however.;	\
	fi

#post-build:	test

.include <bsd.port.post.mk>
