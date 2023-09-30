PORTNAME=	unixbench
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.3-51
DISTVERSIONSUFFIX=	-g6705203
PORTREVISION=	2
CATEGORIES=	benchmarks

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	BYTE magazine's Public Domain benchmark for UNIX
WWW=		https://github.com/kdlucas/byte-unixbench

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	x11perf:x11/x11perf

USES=		gmake gl localbase:ldflags perl5 shebangfix xorg
USE_GL=		gl
SHEBANG_FILES=	Run pgms/gfx-x11
USE_XORG=	x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	kdlucas
GH_PROJECT=	byte-unixbench

WRKSRC_SUBDIR=	UnixBench

MAKE_ENV=	UB_GCC_OPTIONS=" "

SUB_FILES=	unixbench

post-patch:
	${REINPLACE_CMD} -e 's/^CC=gcc/#CC=gcc/' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/^# GRAPHIC_TESTS = defined/GRAPHIC_TESTS = defined/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/unixbench ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unixbench
	${INSTALL_SCRIPT} ${WRKSRC}/Run ${STAGEDIR}${PREFIX}/libexec/unixbench
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unixbench/pgms
	for f in ${WRKSRC}/pgms/* ; do \
		case $$f in \
			*.sh|*gfx-x11) \
				${INSTALL_SCRIPT} $${f} \
					${STAGEDIR}${PREFIX}/libexec/unixbench/pgms/ ;; \
			*.logo|*.base) \
				${INSTALL_DATA} $${f} \
					${STAGEDIR}${PREFIX}/libexec/unixbench/pgms/ ;; \
			*.orig|*.rej|*~) \
				;;\
			*) \
				${INSTALL_PROGRAM} $${f} \
					${STAGEDIR}${PREFIX}/libexec/unixbench/pgms/ ;; \
		esac ; \
	done
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unixbench/testdir
	${INSTALL_DATA} ${WRKSRC}/testdir/* ${STAGEDIR}${PREFIX}/libexec/unixbench/testdir/
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/libexec/unixbench/
	${INSTALL_DATA} ${WRKSRC}/Makefile ${STAGEDIR}${PREFIX}/libexec/unixbench/

.include <bsd.port.mk>
