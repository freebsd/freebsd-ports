# New ports collection makefile for:	pico
# Date created:			16 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#
# All patch files have been taken from mail/pine4

PORTNAME=	pico
PORTVERSION=	4.63
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		http://mirror.sit.wisc.edu/pub/net/mail/pine/ \
		ftp://sunsite.icm.edu.pl/pub/unix/mail/pine/ \
		ftp://ftp.uni-magdeburg.de/pub/mirror/ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/unix/mail/pine/ \
		ftp://ftp.ut.ee/pub/unix/mail/pine/ \
		ftp://gd.tuwien.ac.at/infosys/mail/pine/
DISTNAME=	pine${PORTVERSION}

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	PIne's message COmposition editor

RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

WRKSRC=		${WRKDIR}/pine${PORTVERSION}/pico
PATCH_WRKSRC=	${WRKSRC}/..

MAKEFILE=	makefile.bsf
ALL_TARGET=	pico

MAN1=		pico.1
PLIST_FILES=	bin/pico

post-patch:
	${CP} ${WRKSRC}/osdep/os-bsf.h ${WRKSRC}/osdep/os-bsf.h.presed
	${SED} -e "s:@@PREFIX@@:${PREFIX}:g" \
	${WRKSRC}/osdep/os-bsf.h.presed > ${WRKSRC}/osdep/os-bsf.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pico ${PREFIX}/bin/pico
	${INSTALL_MAN} ${WRKSRC}/../doc/pico.1 ${PREFIX}/man/man1/pico.1

.include <bsd.port.mk>
