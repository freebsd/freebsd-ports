# New ports collection makefile for:	tkcvs
# Version required:     6.0
# Date created:         02 Aug 1996
# Whom:                 shanee@augusta.de
#
# $Id: Makefile,v 1.13 1998/03/20 14:35:16 tg Exp $
#

DISTNAME=	tkcvs-6.0
CATEGORIES=	devel tk80
MASTER_SITES=	http://www.neosoft.com/tcl/ftparchive/sorted/apps/tkcvs-6.0/ \
		http://ftp.sunet.se/pub/lang/tcl/sorted/apps/tkcvs-6.0/

MAINTAINER=	shanee@augusta.de

LIB_DEPENDS=	tk80\\.1\\.:${PORTSDIR}/x11-toolkits/tk80

NO_BUILD=	yes
MAN1=		tkcvs.1 tkdiff.1

post-extract:
	${CP} ${WRKSRC}/tkcvs/tkcvs.n ${WRKSRC}/tkcvs/tkcvs.1
	${CP} ${WRKSRC}/tkdiff/tkdiff.n ${WRKSRC}/tkdiff/tkdiff.1

do-install:
	(cd $(WRKSRC)/tkcvs; ${SETENV} ${MAKE_ENV} sh ./doinstall)

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tkcvs
	${INSTALL_DATA} ${WRKSRC}/README.tkcvs $(PREFIX)/share/doc/tkcvs/
	${INSTALL_DATA} ${WRKSRC}/tkdiff/README $(PREFIX)/share/doc/tkcvs/README.tkdiff
.endif

.include <bsd.port.mk>
