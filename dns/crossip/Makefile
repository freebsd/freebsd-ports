# New ports collection makefile for:	CrossIP
# Date created:				Mon Feb  9 20:27:00 CST 2004
# Whom:					Dan Smith <dan@algenta.com>
#
# $FreeBSD$
#

PORTNAME=	crossip
PORTVERSION=	1.2
CATEGORIES=	dns java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTNAME=	${PORTNAME:L}-${PORTVERSION:S/.p/-pre/:S/.b/-beta/}

MAINTAINER=	dan@algenta.com
COMMENT=	CrossIP is a java DNS update client for the ThatIP protocol

USE_JAVA=	1.2+
USE_ZIP=	yes

NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes

JAVA_VM=	${LOCALBASE}/bin/javavm
TARGET_DIR=	${JAVASHAREDIR}/${PKGNAME}

post-patch:
	@${SED} -e "s|%%JAR_DIR%%|${JAVAJARDIR}|;s|%%JAVAVM%%|${JAVA_VM}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
	${MKDIR} ${JAVAJARDIR}
	${MKDIR} ${TARGET_DIR}
	${CP} -R ${WRKSRC}/* ${TARGET_DIR}
	${LN} -sf ${TARGET_DIR}/lib/CrossIP.jar ${JAVAJARDIR}/CrossIP.jar
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME:L}

.include <bsd.port.mk>
