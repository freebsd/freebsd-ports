# New ports collection makefile for:	cscout
# Date created:			07. Jul 2003
# Whom:				netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cscout
PORTVERSION=	1.16
CATEGORIES=	devel
MASTER_SITES=	http://www.spinellis.gr/cscout/ \
		http://www.dmst.aueb.gr/dds/cscout/
DISTFILES=	${PORTNAME}-${PORTVERSION}-neutral${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-freebsd-${ARCH}${EXTRACT_SUFX}

MAINTAINER=	dds@FreeBSD.org
COMMENT=	Source code analyzer and refactoring browser for collections of C programs

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_REINPLACE=	yes

MAN1=	cscout.1 cswc.1

post-patch:
.if exists(/usr/include/g++/)
	${REINPLACE_CMD} -i "" -e 's:g++-3:g++:g' \
	    ${WRKSRC}/etc/cscout_incs.FBSD_GCC
.endif
	(${SED} -n '1,/Platform defines begin/p' \
	    ${WRKSRC}/etc/cscout_defs.FBSD_GCC && \
		${CPP} -O -dM /dev/null | ${SORT} && \
		${SED} -n '/Platform defines end/,$$p' \
		    ${WRKSRC}/etc/cscout_defs.FBSD_GCC ) \
		    > ${WRKDIR}/cscout_defs.h
	${CP} ${WRKDIR}/cscout_defs.h ${WRKSRC}/etc/cscout_defs.FBSD_GCC

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cscout ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/cswc ${PREFIX}/bin
	cd ${WRKSRC}/etc && ${FIND} . -print | \
	   ${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${PREFIX}/etc/${PORTNAME}
# don't overwrite an existing config
.if !exists(${PREFIX}/etc/${PORTNAME}/cscout_incs.h)
	${INSTALL_DATA} ${WRKSRC}/etc/cscout_incs.FBSD_GCC ${PREFIX}/etc/${PORTNAME}/cscout_incs.h
.endif
.if !exists(${PREFIX}/etc/${PORTNAME}/cscout_defs.h)
	${INSTALL_DATA} ${WRKDIR}/cscout_defs.h ${PREFIX}/etc/${PORTNAME}/cscout_defs.h
.endif
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/example && ${FIND} . -print | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${EXAMPLESDIR}
	cd ${WRKSRC}/doc && ${FIND} . -print | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${DOCSDIR}
.endif
.if !defined(NO_INSTALL_MANPAGES)
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man1
.endfor
.endif

.include <bsd.port.mk>
