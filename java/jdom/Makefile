# New ports collection makefile for:	JDOM
# Date created:		June 1, 2001
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdom
PORTVERSION=	1.0b7
CATEGORIES=	java
MASTER_SITES=	http://www.jdom.org/dist/binary/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/[0-9]*\.[0-9]*//}

MAINTAINER=	znerd@FreeBSD.org

PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
TARGET_DIR?=	${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/[0-9]*\.[0-9]*//}
NO_BUILD=	yes

do-install:
	${MKDIR} ${TARGET_DIR}
	${CP} -r ${WRKSRC}/* ${TARGET_DIR}

.include <bsd.port.mk>
