PORTNAME=	eisl
DISTVERSIONPREFIX=	v
DISTVERSION=	5.69
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interpreter and compiler compatible with ISLisp standard
WWW=		https://github.com/sasagawa888/eisl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BROKEN_armv7=	stage breaks: Abort trap (likely due to the memory allocation problem)
BROKEN_i386=	stage breaks: data segment of more than 500GB is required, see https://github.com/sasagawa888/eisl/issues/218

USES=		gmake gl localbase:ldflags ncurses:port tcl # port because tests need ncurses6-config
USE_GL=		gl glu glut

USE_GITHUB=	yes
GH_ACCOUNT=	sasagawa888

ALL_TARGET=	${PORTNAME}

MAKEFILE=	makefile

# verify/{ilos,misc,object}.lsp are excluded: they report "is bad" failures (method combination, timer resolution)
VERIFY_TESTS=	array bignum char cond block control declare elixir files formeval hiroi io list macro \
		matrix noble number pred seq stream string symbol unicode unwind vector arvyy

CFLAGS+=	-D__BSD_VISIBLE # w/out this there's error: use of undeclared identifier '_SC_NPROCESSORS_CONF'
CFLAGS+=	-I${TCL_INCLUDEDIR}
LDFLAGS+=	-lncursesw

.include <bsd.port.options.mk>

.if ${ARCH} == riscv64
EXTRA_PATCHES=	${FILESDIR}/extra-patch-makefile
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/eisl \
		${STAGEDIR}${PREFIX}/bin/edlis

do-test:
	@cd ${WRKSRC} && for t in ${VERIFY_TESTS}; do \
		${ECHO_MSG} "===> verify/$${t}.lsp"; \
		EASY_ISLISP=${WRKSRC} ./eisl -s verify/$${t}.lsp > ${WRKDIR}/verify-$${t}.log 2>&1 || { ${CAT} ${WRKDIR}/verify-$${t}.log; exit 1; }; \
		if ${GREP} -q ' is bad' ${WRKDIR}/verify-$${t}.log; then ${CAT} ${WRKDIR}/verify-$${t}.log; exit 1; fi; \
	done

# tests as of 5.69: verify/*.lsp: 26 of 29 scripts pass, 0 failures (ilos, misc and object excluded because they fail)

.include <bsd.port.post.mk>
