PORTNAME=	s7
# S7_MAJOR_VERSION / S7_MINOR_VERSION from s7.h
PORTVERSION=	11.2.g20241217
CATEGORIES=	lang lisp

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Scheme interpreter
WWW=		https://ccrma.stanford.edu/software/snd/snd/s7.html

LICENSE=	BSD0CLAUSE

USES=		localbase:ldflags
USE_GITLAB=	yes
GL_SITE=	https://cm-gitlab.stanford.edu
GL_ACCOUNT=	bil
GL_TAGNAME=	f09eadf4dab5b4e6f1c3c2d52e9d6bee6ed21175
USE_LDCONFIG=	yes

CFLAGS+=	-DS7_LOAD_PATH=\"${DATADIR}\" \
		-DHAVE_COMPLEX_NUMBERS \
		-DHAVE_COMPLEX_TRIG \
		-DWITH_SYSTEM_EXTRAS \
		-DWITH_C_LOADER \
		-fno-math-errno \
		-Wno-parentheses-equality

LDFLAGS+=	-Wl,-export-dynamic
LIBS+=		-lm
S7LIBS=		c dl m

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKDIR} \
		USER=${USER}

PORTDOCS=	s7.html s7-ffi.html s7-scm.html

OPTIONS_DEFINE=	DOCS GMP REPL NREPL
OPTIONS_DEFAULT=	GMP REPL
OPTIONS_SUB=	yes
NREPL_DESC=	install notcurses repl (s7-nrepl)
REPL_DESC=	install simple repl (s7-repl)
GMP_LIB_DEPENDS=	libgmp.so:math/gmp \
			libmpfr.so:math/mpfr \
			libmpc.so:math/mpc
GMP_CFLAGS=	-DWITH_GMP
GMP_LIBS=	-lmpc -lmpfr -lgmp
NREPL_LIB_DEPENDS=	libnotcurses-core.so:devel/notcurses

do-build:
	${CC} -fpic -shared ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o ${WRKDIR}/libs7.so ${WRKSRC}/s7.c ${LIBS}
	${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -L${WRKDIR} -o ${WRKDIR}/s7-repl ${WRKSRC}/repl.c -ls7
.for l in ${S7LIBS}
	(cd ${WRKDIR} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${WRKDIR}/s7-repl ${WRKSRC}/lib$l.scm)
.endfor

post-build-NREPL-on:
	${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -L${WRKDIR} -o ${WRKDIR}/s7-nrepl ${WRKSRC}/nrepl.c -ls7 -lnotcurses-core

do-install:
	${INSTALL_LIB} ${WRKDIR}/libs7.so ${STAGEDIR}${PREFIX}/lib/
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

do-install-NREPL-on:
	${INSTALL_PROGRAM} ${WRKDIR}/s7-nrepl ${STAGEDIR}${PREFIX}/bin/

do-install-REPL-on:
	${INSTALL_PROGRAM} ${WRKDIR}/s7-repl ${STAGEDIR}${PREFIX}/bin/

do-test:
	${RLN} ${WRKSRC} ${WRKDIR}/cl
	(cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${WRKDIR}/s7-repl s7test.scm)

.include <bsd.port.mk>
