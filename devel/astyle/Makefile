# New ports collection makefile for:	astyle
# Version required:	1.11.4
# Date created:		31 Jan 1999
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $FreeBSD$
#

DISTNAME=	astyle_1.11.4_src
PKGNAME=	astyle-1.11.4
CATEGORIES= 	devel textproc
MASTER_SITES=	http://gene.md.huji.ac.il/~tald/astyle/stable/src/ \
		http://www.infonex.com/~dacroyle/freebsd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

WRKSRC=		${WRKDIR}/astyle_1.11.4

post-extract:
	perl -pi -e 's/\r//' ${WRKSRC}/*

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig
	${CP} -p ${FILESDIR}/Makefile ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/astyle ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/astyle
	${INSTALL_DATA} ${WRKSRC}/astyle.html ${PREFIX}/share/doc/astyle
.endif

.include <bsd.port.mk>
