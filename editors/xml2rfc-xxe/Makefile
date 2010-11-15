# New ports collection makefile for:	xml2rfc-xxe
# Date created:				9 December 2005
# Whom:					Bill Fenner
#
# $FreeBSD$

PORTNAME=	xml2rfc-xxe
PORTVERSION=	0.7.8
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX=	${XXE_VERSION}

MAINTAINER=	saper@SAPER.INFO
COMMENT=	An xml2rfc configuration for XMLMind XML Editor

RUN_DEPENDS=	xxe:${PORTSDIR}/editors/xxe

USE_ZIP=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/xml2rfc

PLIST_SUB=	XXE_DIR=${XXE_DIR}

post-extract:
	@${RM} -rf ${WRKSRC}/dtd/1.34 ${WRKSRC}/dtd/tmp
.for i in fwip goober goop.diff patch rfc2629.dtd.orig
	@${RM} ${WRKSRC}/dtd/${i}
.endfor

do-install:
	@${RM} -f ${WRKSRC}/xml2rfc_catalog.xml.orig
	@cd ${WRKDIR} && tar cf - xml2rfc | \
		tar -C ${PREFIX}/lib/${XXE_DIR}/addon -xf -

.include "../xxe/Makefile.inc"

.include <bsd.port.mk>
