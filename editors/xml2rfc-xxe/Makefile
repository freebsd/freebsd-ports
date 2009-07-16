# New ports collection makefile for:	xml2rfc-xxe
# Date created:		9 December 2005
# Whom:			Bill Fenner
#
# $FreeBSD$
#

PORTNAME=	xml2rfc-xxe
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.fenron.com/~fenner/ietf/
PKGNAMESUFFIX=	-${XXE_VERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xml2rfc configuration for XMLMind XML Editor

RUN_DEPENDS=	xxe:${PORTSDIR}/editors/xxe

USE_ZIP=	YES
NO_BUILD=	YES

PLIST_SUB=	XXE_DIR=${XXE_DIR}

do-install:
	@cd ${WRKDIR} && tar cf - xml2rfc | \
		tar -C ${PREFIX}/lib/${XXE_DIR}/addon -xf -

BROKEN=	does not compile

#.include "${.CURDIR}/../xxe/Makefile.inc"

.include <bsd.port.mk>
