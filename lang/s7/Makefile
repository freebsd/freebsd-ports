PORTNAME=	s7
PORTVERSION=	g20231215
CATEGORIES=	lang lisp

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Scheme interpreter
WWW=		https://ccrma.stanford.edu/software/snd/snd/s7.html

LICENSE=	BSD0CLAUSE

USES=		localbase:ldflags
USE_GITLAB=	yes
GL_SITE=	https://cm-gitlab.stanford.edu/
GL_ACCOUNT=	bil
GL_TAGNAME=	edc6242088978d09bff053726ec2f8a6ea8f8f72
USE_LDCONFIG=	yes

CFLAGS+=	-DS7_LOAD_PATH=\"${DATADIR}\" \
		-DHAVE_COMPLEX_NUMBERS \
		-DHAVE_COMPLEX_TRIG \
		-DWITH_SYSTEM_EXTRAS \
		-DWITH_C_LOADER

LDFLAGS+=	-Wl,-export-dynamic
LIBS+=		-lm
S7LIBS=		c dl m

PORTDOCS=	s7.html

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
	(cd ${WRKDIR} && ${SETENV} LD_LIBRARY_PATH=${WRKDIR} ${WRKDIR}/s7-repl ${WRKSRC}/lib$l.scm)
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
	${INSTALL_DATA} ${WRKSRC}/s7.html ${STAGEDIR}${DOCSDIR}/

do-install-NREPL-on:
	${INSTALL_PROGRAM} ${WRKDIR}/s7-nrepl ${STAGEDIR}${PREFIX}/bin/

do-install-REPL-on:
	${INSTALL_PROGRAM} ${WRKDIR}/s7-repl ${STAGEDIR}${PREFIX}/bin/

do-test:
	(cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKDIR} ${WRKDIR}/s7-repl s7test.scm)

.include <bsd.port.mk>
