# New ports collection makefile for:	libmicro
# Date created:		2005-08-06
# Whom:			Vsevolod Stakhov <vsevolod@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmicro
PORTVERSION=	0.4.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://hub.opensolaris.org/bin/download/Project+libmicro/Source+Archives/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of utilities to benchmark productivity of system calls

USE_GMAKE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

WRKSRC=		${WRKDIR}/libMicro-${PORTVERSION}
PLIST_SUB=	ARCH=${ARCH}
# Do not strip binaries
STRIP=

do-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/bin
	${MKDIR} ${DATADIR}/bin-${ARCH}
	( cd ${WRKSRC}/bin ; for i in * ; do \
	${INSTALL_PROGRAM} ${WRKSRC}/bin-${ARCH}/$$i ${DATADIR}/bin-${ARCH} ; done )
	${INSTALL_PROGRAM} ${WRKSRC}/bin-${ARCH}/exec_bin ${DATADIR}/bin-${ARCH}
	@for i in ${DATADIR}/bin-${ARCH}/* ; do \
	${LN} -s $$i ${DATADIR}/bin ; done
	${INSTALL_SCRIPT} ${WRKSRC}/bench ${DATADIR}
	@${ECHO} '#!/bin/sh' > ${WRKDIR}/libmicro-bench
	@${ECHO} '(cd ${DATADIR} && ./bench $$1)' >> ${WRKDIR}/libmicro-bench
	${INSTALL_SCRIPT} ${WRKDIR}/libmicro-bench ${PREFIX}/bin/libmicro-bench
	${INSTALL_SCRIPT} ${WRKSRC}/multiview ${PREFIX}/bin/multiview

.include <bsd.port.mk>
