# New ports collection makefile for:	astyle
# Version required:	1.10.1
# Date created:		31 Jan 1999
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id: Makefile,v 1.1.1.1 1999/04/03 01:26:17 steve Exp $
#

DISTNAME=	astyle_1.10.1_src
PKGNAME=	astyle-1.10.1
CATEGORIES= 	devel textproc
MASTER_SITES=	http://gene.md.huji.ac.il/~tald/astyle/stable/src/ \
		http://www.infonex.com/~dacroyle/freebsd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

WRKSRC=		${WRKDIR}/astyle_1.10.1
ALL_TARGET=	astyle

post-extract:
	perl -pi -e 's/\r//' ${WRKSRC}/*

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig
	${CP} -p ${FILESDIR}/Makefile ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/astyle ${PREFIX}/bin/

.include <bsd.port.mk>
