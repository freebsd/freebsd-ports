# New ports collection makefile for:	xml2rfc-xxe
# Date created:		9 December 2005
# Whom:			Bill Fenner
#
# $FreeBSD$
#

PORTNAME=	xml2rfc-xxe
PORTVERSION=	0.7.1
CATEGORIES=	editors
MASTER_SITES=	http://rtg.ietf.org/~fenner/ietf/

MAINTAINER=	fenner@FreeBSD.org
COMMENT=	An xml2rfc configuration for XMLMind XML Editor

RUN_DEPENDS=	xxe:${PORTSDIR}/editors/xxe

USE_ZIP=	YES
NO_BUILD=	YES

XXE_VERSION=	30p1
PLIST_SUB=	XXE_VERSION=${XXE_VERSION}

do-install:
	@cd ${WRKDIR} && tar cf - xml2rfc | \
		tar -C ${PREFIX}/lib/xxe-std-${XXE_VERSION}/addon -xf -

.include <bsd.port.mk>
