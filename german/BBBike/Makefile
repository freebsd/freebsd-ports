# New ports collection makefile for:	BBBike
# Version required:	2.x
# Date created:		Fri Aug 14 15:32:26 CEST 1998
# Whom:			Slaven Rezic <eserte@cs.tu-berlin.de>
#
# $FreeBSD$
#

DISTNAME=	BBBike-2.48
CATEGORIES=	german
MASTER_SITES=	http://pub.cs.tu-berlin.de/src/BBBike/

MAINTAINER=	eserte@cs.tu-berlin.de

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk

USE_PERL5=      YES
PERLEXE=	perl5
POD2MAN=	pod2man

MAN1=		bbbike.1

MYDESTDIR=	${PREFIX}/BBBike

do-build:
	cd ${WRKSRC}/ext/BBBikeXS; ${PERLEXE} Makefile.PL; make all install clean; $(RM) Makefile.old
	cd ${WRKSRC}/ext/VirtArray; ${PERLEXE} Makefile.PL; make all install clean; $(RM) Makefile.old
	cd ${WRKSRC}; ${POD2MAN} --lax bbbike.pod > bbbike.1

do-install:
	-${RM} -rf ${MYDESTDIR}
	${CP} -r  ${WRKSRC} ${MYDESTDIR}
	-${RM} -f ${PREFIX}/bin/bbbike ${PREFIX}/bin/cbbbike
	${LN} -s  ${MYDESTDIR}/bbbike ${PREFIX}/bin/bbbike
	${LN} -s  ${MYDESTDIR}/cbbbike ${PREFIX}/bin/cbbbike
	${INSTALL_MAN} ${WRKSRC}/bbbike.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
