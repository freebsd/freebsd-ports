# Ports collection makefile for: spin
# Version required:	3.24
# Date created:		Oct 23, 1997
# Whom:			jhanna@home.com
#
# $Id: Makefile,v 1.1.1.1 1998/12/12 22:17:48 jseger Exp $
#

DISTNAME=	spin-3.24
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/spin/ \
		ftp://www.netlib.org/spin/ \
		ftp://www.enseeiht.fr/NetLib/spin/ \
		ftp://wcarchive.cdrom.com/netlib/spin/
DISTFILES=	spin324.tar.gz html.tar.gz

MAINTAINER=	jhanna@home.com

DIST_SUBDIR=	spin
WRKSRC=		${WRKDIR}/Src3.2
MAKEFILE=	makefile
ALL_TARGET=	spin

post-extract:
	@cd ${WRKDIR}/Test && ${SH} ${WRKDIR}/Test/examples

pre-build:
	cd ${WRKSRC} && ${MAKE} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spin ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/Xspin3.2/xspin324.tcl ${PREFIX}/bin
	${RM} -f ${PREFIX}/bin/xspin
	ln -s ${PREFIX}/bin/xspin324.tcl ${PREFIX}/bin/xspin

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/spin/Doc
	${MKDIR} ${PREFIX}/share/doc/spin/Examples
	${MKDIR} ${PREFIX}/share/doc/spin/HTML
	${MKDIR} ${PREFIX}/share/doc/spin/Test
	${INSTALL_DATA} ${WRKDIR}/Doc/* ${PREFIX}/share/doc/spin/Doc
	${INSTALL_DATA} ${WRKDIR}/Test/ex.* ${PREFIX}/share/doc/spin/Examples
	${INSTALL_DATA} ${WRKDIR}/HTML/* ${PREFIX}/share/doc/spin/HTML
.for i in README.tests abp erathostenes hello leader leader.ltl leader2 \
	loops pathfinder peterson pftp priorities snoopy sort
	${INSTALL_DATA} ${WRKDIR}/Test/$i ${PREFIX}/share/doc/spin/Test
.endfor
.endif

.include <bsd.port.mk>
