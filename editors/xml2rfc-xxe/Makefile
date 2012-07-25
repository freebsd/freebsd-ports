# New ports collection makefile for:	xml2rfc-xxe
# Date created:				9 December 2005
# Whom:					Bill Fenner
#
# $FreeBSD$

PORTNAME=	xml2rfc-xxe
PORTVERSION=	0.8.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX=	${XXE_VERSION}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	xml2rfc configuration for XMLMind XML editor

RUN_DEPENDS=	xxe:${PORTSDIR}/editors/xxe

USE_ZIP=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/xml2rfc

PLIST_SUB=	XXE_DIR=${XXE_DIR}

post-extract:
	@${RM} ${WRKSRC}/svn-commit.tmp

do-install:
	@cd ${WRKDIR} && tar cf - xml2rfc | \
		tar -C ${PREFIX}/lib/${XXE_DIR}/addon -xf -

.include "../xxe/Makefile.inc"

.include <bsd.port.mk>
