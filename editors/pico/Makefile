# New ports collection makefile for:	pico
# Date created:			16 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#
# All patch files have been taken from mail/pine4

PORTNAME=	pico
PORTVERSION=	4.0
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		http://mirror.sit.wisc.edu/pub/net/mail/pine/ \
		ftp://sunsite.doc.ic.ac.uk/packages/pine/ \
		ftp://ftp.uni-magdeburg.de/pub/mirror/ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/unix/mail/pine/ \
		http://ftp.cs.tu-berlin.de/pub/net/mail/pine/ \
		ftp://sunsite.auc.dk/pub/mail/pine/ \
		ftp://ftp.univ-lyon1.fr/pub/mirrors/unix/pine/ \
		ftp://cis.uniroma2.it/unix/misc/dist/PINE/ \
		ftp://ftp.gin.cz/pub/MIRRORS/ftp.cac.washington.edu/pine/ \
		ftp://ftp.eunet.cz/pub/comm/mail/pine/ \
		ftp://ftp.vse.cz/pub/network/mail/pine/ \
		ftp://sunsite.icm.edu.pl/pub/unix/mail/pine/ \
		ftp://giswitch.sggw.waw.pl/pub/unix/pine/ \
		ftp://ftp.ucr.ac.cr/pub/Unix/mail/pine/ \
		ftp://ftp.ut.ee/pub/unix/mail/pine/
DISTNAME=	pine${pineversion}

MAINTAINER=	jeremy@external.org

WRKSRC=		${WRKDIR}/pine${pineversion}/pico
PATCH_WRKSRC=	${WRKSRC}/..

pineversion=	4.33

MAKEFILE=	makefile.bsf
ALL_TARGET=	pico

MAN1=		pico.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pico ${PREFIX}/bin/pico
	${INSTALL_MAN} ${WRKSRC}/../doc/pico.1 ${PREFIX}/man/man1/pico.1

.include <bsd.port.mk>
