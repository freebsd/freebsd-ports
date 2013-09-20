# Created by: Andreas Kohout <shanee@augusta.de>
# $FreeBSD$

PORTNAME=	tkcvs
PORTVERSION=	8.2.3
CATEGORIES=	devel
MASTER_SITES=	SF \
		http://www.twobarleycorns.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk frontends to CVS and Subversion

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	tkdiff:${PORTSDIR}/textproc/tkdiff

NO_BUILD=	yes

USE_TCL_WRAPPER=yes
USE_TK_WRAPPER=	yes

MAN1=		tkcvs.1

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkcvs/tkcvs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tkcvs/tkcvs.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/lib/tkcvs
	${INSTALL_DATA} ${WRKSRC}/tkcvs/*.tcl ${PREFIX}/lib/tkcvs
	${INSTALL_DATA} ${WRKSRC}/tkcvs/tclIndex ${PREFIX}/lib/tkcvs
	@${MKDIR} ${PREFIX}/lib/tkcvs/bitmaps
	${INSTALL_DATA} ${WRKSRC}/tkcvs/bitmaps/*.gif ${PREFIX}/lib/tkcvs/bitmaps
	${INSTALL_DATA} ${WRKSRC}/tkcvs/bitmaps/*.xbm ${PREFIX}/lib/tkcvs/bitmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGELOG.txt FAQ.txt INSTALL
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
