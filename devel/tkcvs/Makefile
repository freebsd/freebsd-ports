# New ports collection makefile for:	tkcvs
# Version required:     6.0
# Date created:         02 Aug 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $Id: Makefile,v 1.3 1996/08/02 17:33:30 chuckr Exp $
#

DISTNAME=	tkcvs-6.0
CATEGORIES+=	devel
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/NEW/

MAINTAINER=	shanee@rabbit.augusta.de

LIB_DEPENDS=	tcl75\\.1\\.:${PORTSDIR}/lang/tcl75 \
		tk41\\.1\\.:${PORTSDIR}/x11/tk41

NO_BUILD=	yes

do-install:
	(cd $(WRKSRC)/tkcvs; sh ./doinstall)

post-extract:
	cp ${WRKDIR}/tkcvs-6.0/tkcvs/tkcvs.n ${WRKDIR}/tkcvs-6.0/tkcvs/tkcvs.1
	cp ${WRKDIR}/tkcvs-6.0/tkdiff/tkdiff.n ${WRKDIR}/tkcvs-6.0/tkdiff/tkdiff.1

post-install:
.if !defined(NOPORTDOCS)
	cp ${WRKDIR}/tkcvs-6.0/README.tkcvs $(PREFIX)/lib/tkcvs/
	cp ${WRKDIR}/tkcvs-6.0/tkdiff/README $(PREFIX)/lib/tkcvs/README.tkdiff
.endif
.if !defined(NOMANCOMPRESS)
	gzip -9nf $(PREFIX)/man/man1/tkcvs.1
	gzip -9nf $(PREFIX)/man/man1/tkdiff.1
.endif

.include <bsd.port.mk>
