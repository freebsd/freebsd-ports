# New ports collection makefile for:	ptoc
# Date created:				10 December 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		ptoc
PORTVERSION=		3.41
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.netsw.org/netsw/SoftEng/Lang/Pascal/ \
			ftp://ftp.u-aizu.ac.jp/pub/lang/netsw/Pascal/ \
			ftp://ftp.ecrc.net/pub/netsw/SoftEng/Lang/Pascal/

MAINTAINER=		ports@FreeBSD.org

MAKEFILE=		makefile

USE_XLIB=		yes
WRKSRC=			${WRKDIR}/ptoc

pre-build:
	@ ${MV} ${WRKSRC}/makefile.bsd ${WRKSRC}/makefile
	@ ${MV} ${WRKSRC}/Xbgi/makefile.bsd ${WRKSRC}/Xbgi/makefile
	@ ${MV} ${WRKSRC}/examples/makefile.bsd ${WRKSRC}/examples/makefile

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

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/ptoc
	@ ${INSTALL_DATA} ${WRKSRC}/Readme.htm ${PREFIX}/share/doc/ptoc
.endif

.include <bsd.port.mk>
