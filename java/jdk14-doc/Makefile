# New ports collection makefile for:	jdk-doc-1.4
# Date created:		June 1, 2001
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk-doc
PORTVERSION=	${JDK_VERSION:S/_/./g:S/-beta/b/}
CATEGORIES=	java
MASTER_SITES=	#
DISTNAME=	j2sdk-${JDK_VERSION:S/./_/g}-doc

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java Development Kit 1.4 Documentation

LATEST_LINK=	jdk14-doc
NO_CDROM=	"License does not allow distribution with fee."
RESTRICTED=	"This documentation is under license and export control."

TARGET_DIR?=	${PREFIX}/share/doc/jdk${JDK_MAJOR_VER}

WRKSRC=		${WRKDIR}/docs
JDK_VERSION=	1.4.2
JDK_MAJOR_VER=	${JDK_VERSION:R}
BUNDLE_ID=	8602
DOWNLOAD_URL=	http://java.sun.com/webapps/download/Display?BundleId=${BUNDLE_ID}

NO_BUILD=	yes
PLIST=		${WRKDIR}/PLIST
USE_ZIP=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch ${DISTNAME}${EXTRACT_SUFX} from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
	@${ECHO_CMD} -n ">> Creating directory ${TARGET_DIR}..."
	@${MKDIR} ${TARGET_DIR}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Copying files..."
	@${CP} -r ${WRKSRC}/* ${TARGET_DIR}
	@${ECHO_CMD} " [ DONE ]"

post-extract:
	@${ECHO_CMD} -n ">> Creating packing list..."
	@${ECHO_CMD} "@cwd ${TARGET_DIR}" > ${PLIST}
	@${FIND} ${WRKSRC} -type f -print | \
		${SED} -e "s,${WRKSRC}/*,," >> ${PLIST}
	@${FIND} ${WRKSRC} -type d -print | ${SORT} -r | \
		${SED} -e "s,${WRKSRC}/*,," -e "/^$$/d" -e "s,^,@dirrm ," >> ${PLIST}
	@${ECHO_CMD} "@cwd /" >> ${PLIST}
	@${ECHO_CMD} "@dirrm ${TARGET_DIR}" >> ${PLIST}
	@${ECHO_CMD} " [ DONE ]"

.include <bsd.port.post.mk>
