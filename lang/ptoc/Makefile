# New ports collection makefile for:	ptoc
# Version required:			2.01
# Date created:				10 December 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/03/28 19:37:51 asami Exp $
#

DISTNAME=		ptoc
PKGNAME=		ptoc-2.01
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/pascal
EXTRACT_SUFX=		.tgz

MAINTAINER=		andy@icc.surw.chel.su

MAKEFILE=		makefile

pre-build:
	@ ${RM} ${WRKSRC}/libXbgi.a
	@ ${RM} ${WRKSRC}/libptoc.a

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
.for file in ptoc.pas tptoc.pas graph.pas
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/ptoc
.endfor
	@ ${MKDIR} ${PREFIX}/share/doc/ptoc
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ptoc
	@ ${INSTALL_DATA} ${WRKSRC}/paslib.doc ${PREFIX}/share/doc/ptoc
	@ ${MKDIR} ${PREFIX}/share/examples/ptoc
	@ ${INSTALL_DATA} ${FILESDIR}/Makefile ${PREFIX}/share/examples/ptoc
.for file in bgidemo.pas coord.txt hello.pas impact.pas lister.pas polut2.pas printer.pas q2.txt random.txt rename.pas set.pas test.pas tpascal.pas trinor.pas vibrkinp.pas vibrkinp.txt vibrtabl.pas war2.pas xy2orig.txt
	@ ${INSTALL_DATA} ${WRKSRC}/examples/${file} ${PREFIX}/share/examples/ptoc
.endfor

.include <bsd.port.mk>
