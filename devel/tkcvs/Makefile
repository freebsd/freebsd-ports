# New ports collection makefile for:	tkcvs
# Date created:		02 Aug 1996
# Whom:			shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	tkcvs
PORTVERSION=	8.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.twobarleycorns.net/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	andrew.nau.ua@gmail.com
COMMENT=	Tcl/Tk frontends to CVS, Subversion and diff

NO_BUILD=	yes
USE_TK=		84

MAN1=		tkcvs.1
PORTDOCS=	CHANGELOG COPYING FAQ INSTALL vendor5readme.pdf
PATCH_TCL_SCRIPTS=	doinstall.tcl tkcvs/mkindex
PATCH_TK_SCRIPTS=	doinstall.tcl tkcvs/tkcvs.tcl tkdiff/tkdiff

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkcvs/tkcvs.tcl ${PREFIX}/bin/tkcvs
	@${INSTALL_SCRIPT} ${WRKSRC}/tkdiff/tkdiff ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/tkcvs/tkcvs.1 ${MAN1PREFIX}/man/man1/
	@${INSTALL} -d ${PREFIX}/lib/tkcvs/bitmaps
	@${INSTALL_DATA} ${WRKSRC}/tkcvs/*tcl ${PREFIX}/lib/tkcvs/
	@${INSTALL_DATA} ${WRKSRC}/tkcvs/tclIndex ${PREFIX}/lib/tkcvs/
	@${INSTALL_DATA} ${WRKSRC}/tkcvs/bitmaps/* ${PREFIX}/lib/tkcvs/bitmaps/
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
