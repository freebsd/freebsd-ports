# New ports collection makefile for:	jlint
# Date created:		June 2, 2001
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jlint
PORTVERSION=	2.3
CATEGORIES=	java
MASTER_SITES=	http://artho.com/jlint/ \
		http://www.metaverse.nl/~ernst/

MAINTAINER=	znerd@FreeBSD.org

PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
TARGET_DIR?=	${PREFIX}/bin

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${TARGET_DIR}
	${CP} ${WRKSRC}/jlint ${TARGET_DIR}
	${CP} ${WRKSRC}/antic ${TARGET_DIR}
	${CHMOD} 755 ${TARGET_DIR}/jlint ${TARGET_DIR}/antic

.include <bsd.port.post.mk>
