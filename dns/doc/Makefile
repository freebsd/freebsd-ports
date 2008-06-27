# New ports collection makefile for:	doc
# Date created:			28 November 1999
# Whom:				MIHIRA Yoshiro <sanpei@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	doc
PORTVERSION=	2.2.3
CATEGORIES=	dns
MASTER_SITES=   ${MASTER_SITE_LOCAL} \
		ftp://ftp.shub-internet.org/pub/shub/brad/dns/
MASTER_SITE_SUBDIR=	sanpei

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Diagnose unhealthy DNS domains

USE_BZIP2=	yes

AUX_DIR=	lib/doc
AUX_FILES=	doc-1.awk doc-3.awk doc-4.awk INFO RFC.XXXX

MAN8=		doc.8

do-build:
	@${MV} ${WRKSRC}/doc ${WRKSRC}/doc.org
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' -e 's|$${AUX_DIR}|${AUX_DIR}|g' ${WRKSRC}/doc.org \
	> ${WRKSRC}/doc

do-install:
	@${MKDIR} ${PREFIX}/${AUX_DIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/doc ${PREFIX}/bin/doc
	@for file in ${AUX_FILES}; do \
	    ${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/${AUX_DIR}/ ; \
	done
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_DATA} ${WRKSRC}/doc.8 ${PREFIX}/man/man8/doc.8
.endif

.include <bsd.port.mk>
