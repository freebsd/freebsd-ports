# New ports collection makefile for:	ptoc
# Version required:			3.34
# Date created:				10 December 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.5 1998/10/14 23:56:40 jseger Exp $
#

DISTNAME=		ptoc_3.34
PKGNAME=		ptoc-3.34
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/pascal

MAINTAINER=		andy@icc.surw.chel.su

MAKEFILE=		makefile

USE_XLIB=		yes
WRKSRC=			${WRKDIR}/ptoc

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cganal ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/ptoc ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/ptoc.cfg ${PREFIX}/etc
	@ ${INSTALL_DATA} ${WRKSRC}/libptoc.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/libXbgi.a ${PREFIX}/lib
	@ ${MKDIR} ${PREFIX}/include/ptoc
.for file in array.h graph.h io.h paslib.h ptoc.h set.h
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/ptoc
.endfor
	@ ${MKDIR} ${PREFIX}/share/ptoc
.for file in graph.pas ptoc.pas tptoc.pas
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/ptoc
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/ptoc
	@ ${INSTALL_DATA} ${WRKSRC}/examples/makefile ${PREFIX}/share/examples/ptoc/Makefile
.for file in bgidemo.pas coord.txt hello.pas impact.pas lister.pas polut2.pas printer.pas q2.txt random.txt rename.pas set.pas test.pas tpascal.pas trinor.pas vibrkinp.pas vibrkinp.txt vibrtabl.pas war2.pas war2.txt xy2orig.txt
	@ ${INSTALL_DATA} ${WRKSRC}/examples/${file} ${PREFIX}/share/examples/ptoc
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/ptoc
	@ ${INSTALL_DATA} ${WRKSRC}/Readme.htm ${PREFIX}/share/doc/ptoc
.endif

.include <bsd.port.mk>
