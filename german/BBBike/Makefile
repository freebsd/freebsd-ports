# New ports collection makefile for:	BBBike
# Version required:	2.x
# Date created:		Fri Aug 14 15:32:26 CEST 1998
# Whom:			Slaven Rezic <eserte@cs.tu-berlin.de>
#
# $Id: Makefile.tmpl,v 1.3 1998/08/24 00:19:56 eserte Exp $
#

DISTNAME=	BBBike-2.48
CATEGORIES=	german
MASTER_SITES=	http://pub.cs.tu-berlin.de/src/BBBike/

MAINTAINER=	eserte@cs.tu-berlin.de

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/Tk.pm:${PORTSDIR}/x11/p5-Tk

USE_PERL5=      YES
PERLEXE=	perl5
POD2MAN=	pod2man

NO_CONFIGURE=	YES

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
