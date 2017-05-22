# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmicro
PORTVERSION=	0.4.1
CATEGORIES=	benchmarks
MASTER_SITES=	http://hub.opensolaris.org/bin/download/Project+libmicro/Source+Archives/ \
		LOCAL/bdrewery/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of utilities to benchmark productivity of system calls

LICENSE=	CDDL

BROKEN_aarch64=		Fails to build: bin-aarch64: no such file or directory
BROKEN_armv6=		Fails to build: bin-armv6: no such file or directory
BROKEN_mips64=		Fails to build: bin-mips64: no such file or directory
BROKEN_powerpc64=	Fails to build: bin-powerpc64: no such file or directory

USES=		gmake
WRKSRC=		${WRKDIR}/libMicro-${PORTVERSION}
STRIP=		# Do not strip binaries
PLIST_SUB=	ARCH="${ARCH}"
PKGLIBDIR=	${PREFIX}/lib/${PORTNAME}

post-build:
	${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/libmicro-bench
	${ECHO_CMD} '(cd ${PKGLIBDIR} && ./bench $$1)' \
		>> ${WRKDIR}/libmicro-bench.sh

do-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} libmicro-bench.sh \
		${STAGEDIR}${PREFIX}/bin/libmicro-bench)
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} multiview.sh \
		${STAGEDIR}${PREFIX}/bin/multiview)
	@${MKDIR} ${STAGEDIR}${PKGLIBDIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} bench.sh \
		${STAGEDIR}${PKGLIBDIR}/bench)
	@${MKDIR} ${STAGEDIR}${PKGLIBDIR}/bin-${ARCH}
	(cd ${WRKSRC}/bin-${ARCH} \
		&& ${INSTALL_PROGRAM} exec_bin ${STAGEDIR}${PKGLIBDIR}/bin-${ARCH})
	(cd ${WRKSRC}/bin ; for i in * ; do ${INSTALL_PROGRAM} \
		${WRKSRC}/bin-${ARCH}/$$i ${STAGEDIR}${PKGLIBDIR}/bin-${ARCH} ; done)
	@${MKDIR} ${STAGEDIR}${PKGLIBDIR}/bin
	(cd ${STAGEDIR}${PKGLIBDIR}/bin-${ARCH} ; for i in * ; do ${LN} -s \
		../bin-${ARCH}/$$i ../bin ; done)

.include <bsd.port.mk>
