COMMENT=	Scheme interpreter

USE_LDCONFIG=	yes
LIBS+=		-lm
LIBS7=		${WRKDIR}/libs7.so.0
S7LIBS=		c dl m

PORTDOCS=	s7.html s7-ffi.html s7-scm.html

OPTIONS_DEFINE=	DOCS GMP REPL
OPTIONS_DEFAULT=	GMP REPL
OPTIONS_SUB=	yes
REPL_DESC=	install simple repl (s7-repl)
GMP_LIB_DEPENDS=	libgmp.so:math/gmp \
			libmpfr.so:math/mpfr \
			libmpc.so:math/mpc
GMP_CFLAGS=	-DWITH_GMP
GMP_LIBS=	-lmpc -lmpfr -lgmp

do-build:
	${CC} -fpic -shared ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -Wl,--soname=libs7.so.0 \
		-o ${LIBS7} ${WRKSRC}/s7.c ${LIBS}
	${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o ${WRKDIR}/s7-repl ${WRKSRC}/repl.c ${LIBS7}
.for l in ${S7LIBS}
	(cd ${WRKDIR} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${WRKDIR}/s7-repl ${WRKSRC}/lib$l.scm)
.endfor

do-install:
	${INSTALL_LIB} ${LIBS7} ${STAGEDIR}${PREFIX}/lib/libs7.so.0.0.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/libs7.so.0.0.0 ${STAGEDIR}${PREFIX}/lib/libs7.so.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/libs7.so.0.0.0 ${STAGEDIR}${PREFIX}/lib/libs7.so
	${INSTALL_DATA} ${WRKSRC}/s7.h ${STAGEDIR}${PREFIX}/include/
	${MKDIR} ${STAGEDIR}${DATADIR}/tools
.for l in ${S7LIBS}
	${INSTALL_LIB} ${WRKDIR}/lib$l_s7.so ${STAGEDIR}${DATADIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.scm ${STAGEDIR}/${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/tools/*.scm ${STAGEDIR}/${DATADIR}/tools

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}/
.endfor

do-install-REPL-on:
	${INSTALL_PROGRAM} ${WRKDIR}/s7-repl ${STAGEDIR}${PREFIX}/bin/

do-test:
	${RM} -r ${WRKDIR}/cl ${WRKDIR}/test
	${RLN} ${WRKSRC} ${WRKDIR}/cl
	${MKDIR} ${WRKDIR}/test
	(cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${WRKDIR}/s7-repl s7test.scm)

.include "Makefile.master"
