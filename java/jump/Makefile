# New ports collection makefile for:	JUMP Ultimate Math Package
# Date created:				June 13, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jump
PORTVERSION=	0.3
CATEGORIES=	java math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.metaverse.nl/~ernst/
MASTER_SITE_SUBDIR=	jump-math

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/jakarta-ant

MAINTAINER=	znerd@FreeBSD.org

USE_JAVA=	1.2+

PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
TARGET_DIR?=	${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}
ANT?=		${LOCALBASE}/bin/ant
ANT_TARGET=	jar javadoc

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Creating directory ${TARGET_DIR}..."
	@${MKDIR} ${TARGET_DIR}
	@${ECHO} " [ DONE ]"

	@${ECHO} -n ">> Copying files..."
	@${CP} -r ${WRKSRC}/* ${TARGET_DIR}
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
