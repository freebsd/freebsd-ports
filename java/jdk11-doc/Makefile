# New ports collection makefile for:	JDK documentation
# Date created:		Mon Mar  8 10:10:42 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	jdk-doc
PORTVERSION=	${JDK_VERSION:S/_/./g}
CATEGORIES=	java
MASTER_SITES=	http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
DISTNAME=	jdk-${JDK_VERSION:S/./_/g}-doc

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java Development Kit 1.1 Documentation

LATEST_LINK=	jdk11-doc
TARGET_DIR?=	${PREFIX}/share/doc/jdk${JDK_MAJOR_VER}

WRKSRC=		${WRKDIR}/jdk${JDK_VERSION:C/_.*\$//g}/docs
JDK_VERSION=	1.1.8_003
JDK_MAJOR_VER=	${JDK_VERSION:R}
DOWNLOAD_URL=	http://java.sun.com/jdk/${JDK_MAJOR_VER}/docs.html

NO_BUILD=	yes
PLIST=		${WRKDIR}/PLIST

.include <bsd.port.pre.mk>

pre-install:
	@${ECHO_CMD} -n ">> Removing ${PLIST}..."
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@${ECHO_CMD} " [ DONE ]"

do-install:
	@${ECHO_CMD} -n ">> Creating directory ${TARGET_DIR}..."
	@${MKDIR} ${TARGET_DIR}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Copying files..."
	@${CP} -r ${WRKSRC}/* ${TARGET_DIR}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Creating packing list..."
	@${FIND} ${TARGET_DIR} -type f -print | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${FIND} ${TARGET_DIR} -type d -print | ${SORT} -r | \
		${SED} -e "s,${PREFIX}/*,," -e "s,^,@dirrm ,g" >> ${PLIST}
	@${ECHO_CMD} " [ DONE ]"

.include <bsd.port.post.mk>
