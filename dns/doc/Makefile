# Created by: MIHIRA Yoshiro <sanpei@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	doc
PORTVERSION=	2.2.3
CATEGORIES=	dns
MASTER_SITES=   LOCAL/sanpei \
		ftp://ftp.shub-internet.org/pub/shub/brad/dns/

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Diagnose unhealthy DNS domains

RUN_DEPENDS=	dig:dns/bind-tools

USES=		tar:bzip2

AUX_DIR=	lib/doc
AUX_FILES=	doc-1.awk doc-3.awk doc-4.awk INFO RFC.XXXX

do-build:
	@${MV} ${WRKSRC}/doc ${WRKSRC}/doc.org
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' -e 's|$${AUX_DIR}|${AUX_DIR}|g' ${WRKSRC}/doc.org \
		> ${WRKSRC}/doc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${AUX_DIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/doc ${STAGEDIR}${PREFIX}/bin/doc
.for f in ${AUX_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${AUX_DIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc.8 ${STAGEDIR}${PREFIX}/man/man8/doc.8

.include <bsd.port.mk>
