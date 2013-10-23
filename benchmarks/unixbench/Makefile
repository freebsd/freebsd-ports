# Created by: se
# $FreeBSD$

PORTNAME=	unixbench
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.tux.org/pub/tux/benchmarks/System/unixbench/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BYTE magazine's Public Domain benchmark for UNIX

SUB_FILES=	unixbench
MAKE_JOBS_UNSAFE=	yes

post-extract:
	${RM} -f ${WRKSRC}/pgms/select

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/unixbench ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/unixbench
	for f in Run ; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$${f} ${STAGEDIR}${PREFIX}/lib/unixbench/ ; \
	done
	for f in Makefile README ; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${STAGEDIR}${PREFIX}/lib/unixbench/ ; \
	done
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/unixbench/pgms
	for f in ${WRKSRC}/pgms/* ; do \
		case $$f in \
	*.awk|*.sh|*perlbench) \
		${INSTALL_SCRIPT} $${f} ${STAGEDIR}${PREFIX}/lib/unixbench/pgms/ ;; \
	*.logo|*.base) \
		${INSTALL_SCRIPT} $${f} ${STAGEDIR}${PREFIX}/lib/unixbench/pgms/ ;; \
	*.orig|*.rej|*~) \
		;;\
	*) \
		${INSTALL_PROGRAM} $${f} ${STAGEDIR}${PREFIX}/lib/unixbench/pgms/ ;; \
		esac ; \
	done
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/unixbench/results
#	for f in ${WRKSRC}/results/* ; do \
#		${INSTALL_DATA} $${f} ${STAGEDIR}${PREFIX}/lib/unixbench/results/ ; \
#	done
	-${MKDIR} ${STAGEDIR}${PREFIX}/lib/unixbench/testdir
	for f in ${WRKSRC}/testdir/* ; do \
		${INSTALL_DATA} $${f} ${STAGEDIR}${PREFIX}/lib/unixbench/testdir/ ; \
	done

.include <bsd.port.mk>
