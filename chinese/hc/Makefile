# Created by: David O'Brien (obrien@FreeBSD.org)
# $FreeBSD$

PORTNAME=	hc
PORTVERSION=	3.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/convert/
DISTFILES=	hc-30.tar.gz hc-supp.tab

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hanzi Converter -- converts between GB and BIG-5 codes

WRKSRC=		${WRKDIR}/hc3
EXTRACT_ONLY=	hc-30.tar.gz
ALL_TARGET=	hc b2g g2b

pre-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/hclib.c

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/chinese
	${INSTALL_PROGRAM} ${WRKSRC}/hc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/b2g ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/g2b ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/hc.tab ${STAGEDIR}${PREFIX}/share/chinese
	${INSTALL_DATA} ${DISTDIR}/hc-supp.tab ${STAGEDIR}${PREFIX}/share/chinese
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
