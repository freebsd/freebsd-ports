# Created by: se
# $FreeBSD$

PORTNAME=	unixbench
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.3
CATEGORIES=	benchmarks

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	BYTE magazine's Public Domain benchmark for UNIX

LICENSE=	GPLv2

RUN_DEPENDS=	x11perf:x11/x11perf

USES=		gmake perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	kdlucas
GH_PROJECT=	byte-unixbench
WRKSRC_SUBDIR=	UnixBench

SUB_FILES=	unixbench
SHEBANG_FILES=	Run pgms/gfx-x11

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
