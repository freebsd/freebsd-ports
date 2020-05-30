# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmicro
PORTVERSION=	0.4.1
CATEGORIES=	benchmarks
MASTER_SITES=	LOCAL/bdrewery/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of utilities to benchmark productivity of system calls

LICENSE=	CDDL

BROKEN_mips64=		Fails to build: bin-mips64: no such file or directory

USES=		gmake
WRKSRC=		${WRKDIR}/libMicro-${PORTVERSION}
STRIP=		# Do not strip binaries
PLIST_SUB=	ARCH="${LIBMICRO_ARCH}"
PKGLIBDIR=	${PREFIX}/lib/${PORTNAME}

LIBMICRO_ARCH=	${ARCH:S/aarch64/arm64/:C/armv.*/arm/:S/powerpc64/powerpc/}

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
	@${MKDIR} ${STAGEDIR}${PKGLIBDIR}/bin-${LIBMICRO_ARCH}
	(cd ${WRKSRC}/bin-${LIBMICRO_ARCH} \
		&& ${INSTALL_PROGRAM} exec_bin ${STAGEDIR}${PKGLIBDIR}/bin-${LIBMICRO_ARCH})
	(cd ${WRKSRC}/bin ; for i in * ; do ${INSTALL_PROGRAM} \
		${WRKSRC}/bin-${LIBMICRO_ARCH}/$$i ${STAGEDIR}${PKGLIBDIR}/bin-${LIBMICRO_ARCH} ; done)
	@${MKDIR} ${STAGEDIR}${PKGLIBDIR}/bin
	(cd ${STAGEDIR}${PKGLIBDIR}/bin-${LIBMICRO_ARCH} ; for i in * ; do ${LN} -s \
		../bin-${LIBMICRO_ARCH}/$$i ../bin ; done)

.include <bsd.port.mk>
