# New ports collection makefile for:	fnorb
# Date created:		12 Septermber 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	fnorb
PORTVERSION=	1.1
CATEGORIES=	devel python
MASTER_SITES=	http://www.fnorb.org/download/ \
		ftp://ftp.dstc.edu.au/DSTC/fnorb/

MAINTAINER=	johann@egenetics.com

NO_CDROM=	Free for academic, research and non-commercial purposes only
WRKSRC=		${WRKDIR}/Fnorb-${PORTVERSION}/src
USE_PYTHON=	yes

do-configure:
	@ (cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	  Makefile.pre.in boot)

FNORB_DIR=	${PYTHON_LIBDIR}/site-packages/Fnorb
FNORB_SHAREDIR=	${PREFIX}/share/fnorb
FNORB_DOCDIR=	${PREFIX}/share/doc/fnorb

post-install:
	@ ${MKDIR} ${FNORB_DIR}
	@ (cd ${WRKSRC}/../ && find *.py compiler cos orb parser \
	  | cpio --quiet -pdum -R ${BINOWN}:${BINGRP} ${FNORB_DIR})
	@ ${MKDIR} ${FNORB_SHAREDIR}
	@ (cd ${WRKSRC}/../ && find script examples \! -name \*.bat \
	  | cpio --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${FNORB_SHAREDIR})
	@ ${INSTALL_DATA} ${WRKSRC}/../etc/fnorb.cfg \
	  ${PREFIX}/etc/fnorb.cfg.sample
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${FNORB_DOCDIR}
	@ (cd ${WRKSRC}/../doc && find . \
	  | cpio --quiet -pdum -R ${MANOWN}:${MANGRP} ${FNORB_DOCDIR})
	@ (${CHMOD} -R u-x ${FNORB_DOCDIR} && ${CHMOD} -R u+X ${FNORB_DOCDIR})
.for file in ANNOUNCE CHANGES README LICENSE.HTML
	@ ${INSTALL_MAN} ${WRKSRC}/../${file} ${FNORB_DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
