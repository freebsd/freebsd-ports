# New ports collection makefile for:	tkcvs
# Version required:     6.0
# Date created:         02 Aug 1996
# Whom:                 shanee@augusta.de
#
# $Id: Makefile,v 1.9 1997/05/29 02:26:46 fenner Exp $
#

DISTNAME=	tkcvs-6.0
CATEGORIES=	devel tk41
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/sorted/apps/

MAINTAINER=	shanee@augusta.de

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

NO_BUILD=	yes

MAN1=		tkcvs.1 tkdiff.1

do-install:
	(cd $(WRKSRC)/tkcvs; sh ./doinstall)

post-extract:
	cp ${WRKSRC}/tkcvs/tkcvs.n ${WRKSRC}/tkcvs/tkcvs.1
	cp ${WRKSRC}/tkdiff/tkdiff.n ${WRKSRC}/tkdiff/tkdiff.1

post-install:
.if !defined(NOPORTDOCS)
	install -c ${WRKSRC}/README.tkcvs $(PREFIX)/lib/tkcvs/
	install -c ${WRKSRC}/tkdiff/README $(PREFIX)/lib/tkcvs/README.tkdiff
.endif

.include <bsd.port.mk>
