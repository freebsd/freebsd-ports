# New ports collection makefile for:	cxref
# Version required:	1.2b
# Date created:		23 October 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.2 1996/10/25 06:11:05 tg Exp $
#

DISTNAME=	cxref-1.2
PKGNAME=	cxref-1.2b
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/unix/unix/tools/
EXTRACT_SUFX=	.tgz

PATCHFILES=	cxref-1.2-1.2a.diff.gz cxref-1.2a-1.2b.diff.gz
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	tg@freebsd.org

WRKSRC=		${WRKDIR}/cxref
USE_GMAKE=	yes
ALL_TARGET=	program
PATCH_DIST_STRIP=	-p1

DOCDIR=		${PREFIX}/share/doc/cxref

do-install:
	@mkdir -p ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cxref ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/query/cxref-query ${PREFIX}/bin
	@mkdir -p ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/cxref.sty ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/fonts.sty ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/page.sty ${DOCDIR}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README.c ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}/README.cxref
	${INSTALL_DATA} ${WRKSRC}/query/README ${DOCDIR}/README.query
	@${ECHO_MSG} 
	@${ECHO_MSG} "Unfortunately, there's no man page."
	@${ECHO_MSG} "Please see ${DOCDIR}/README* for documentation."
.endif
	@${ECHO_MSG} 
	@${ECHO_MSG} "If you want to use the LaTeX output from cxref,"
	@${ECHO_MSG} "you should copy ${DOCDIR}/*.sty"
	@${ECHO_MSG} "to a directory where TeX looks for its input files."
	@${ECHO_MSG} 

.include <bsd.port.mk>
