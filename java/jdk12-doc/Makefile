# New ports collection makefile for:	jdk-doc-1.2
# Date created:		June 1, 2001
# Whom:			Ernst de Haan <znerd@FreeBSD.org
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
COMMENT=	Java Development Kit 1.2 Documentation

LATEST_LINK=	jdk12-doc
NO_CDROM=	"License does not allow distribution with fee."
RESTRICTED=	"This software is under license and export control."

TARGET_DIR?=	${PREFIX}/share/doc/jdk${JDK_MAJOR_VER}

WRKSRC=		${WRKDIR}/jdk${JDK_VERSION:C/_.*\$//g}/docs
JDK_VERSION=	1.2.2_006
JDK_MAJOR_VER=	${JDK_VERSION:R}

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
