# New ports collection makefile for:    CMUCL
# Date created:         Jul, 15, 1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#
#

PORTNAME=	cmucl
PORTVERSION=	18e
CATEGORIES=	lang
MASTER_SITES=	http://www.pmsf.de/pub/cmucl/release/18e/ \
		ftp://ftp.averillpark.net/cmucl/release/18e/ \
		ftp://ftp.linux.org.uk/pub/lisp/cmucl/release/18e/ \
		ftp://ftp.cn.freebsd.org/pub/cmucl/release/18e/
DISTNAME=	cmucl-18e-x86-freebsd

MAINTAINER=	cracauer@cons.org
COMMENT=	The CMU implementation of Common Lisp

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	YES
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
MAN1=		lisp.1 cmucl.1

.include <bsd.port.pre.mk>

# portlint wants this earlier but this doesn't work because weneed OSVERSION
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif

do-install:
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/bin/lisp ${PREFIX}/bin
	(cd ${WRKDIR} && ${FIND} lib | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX})
	-${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/cmucl/* ${DOCSDIR}
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/man/man1/cmucl.1 \
		${PREFIX}/man/man1
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/man/man1/lisp.1 \
		${PREFIX}/man/man1

.include <bsd.port.post.mk>
