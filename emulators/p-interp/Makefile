# New ports collection makefile for:    p-interp
# Date created:         21 Aug 2001
# Whom:                 Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	p-interp
PORTVERSION=	0.5
CATEGORIES=	emulators
MASTER_SITES=	http://www.klebsch.de/ \
		ftp://ftp.apple.asimov.net/pub/apple_II/images/utility/programming/apple_pascal/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		apple_pascal_0.dsk.gz apple_pascal_1.dsk.gz \
		apple_pascal_2.dsk.gz apple_pascal_3.dsk.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nsayer@FreeBSD.org

MAN1=	ucsd.1 svolio.1 svolcvt.1

.include <bsd.port.pre.mk>

post-extract:
		@cp ${DISTDIR}/apple_pascal_?.dsk.gz ${WRKDIR}/${DISTNAME}
		@gunzip ${WRKDIR}/${DISTNAME}/apple_pascal_?.dsk.gz

post-patch:
		cd ${WRKDIR}/${DISTNAME} && ${MAKE} depend

pre-install:
		${MKDIR} ${PREFIX}/share/doc/p-interp
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/p-interp
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/COPYING ${PREFIX}/share/doc/p-interp

.include <bsd.port.post.mk>
