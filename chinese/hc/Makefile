# ex:ts=8
# Ports collection makefile for:  hc
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	hc
PORTVERSION=	3.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.ifcss.org/pub/software/unix/convert/  \
		ftp://ftp.edu.tw/Chinese/ifcss/software/unix/convert/  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/convert/
DISTFILES=	hc-30.tar.gz  hc-supp.tab

MAINTAINER=	obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/hc3
EXTRACT_ONLY=	hc-30.tar.gz
ALL_TARGET=	hc b2g g2b
MAN1=		hc.1

pre-patch:
	@${PERL} -pi -e 's|malloc.h|stdlib.h|' ${WRKSRC}/hclib.c

do-install:
	@${MKDIR} ${PREFIX}/share/chinese
	${INSTALL_PROGRAM} ${WRKSRC}/hc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/b2g ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/g2b ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/hc.tab ${PREFIX}/share/chinese
	${INSTALL_DATA} ${DISTDIR}/hc-supp.tab ${PREFIX}/share/chinese
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
