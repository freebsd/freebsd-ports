# New ports collection makefile for:	eclipse-pmd
# Date created:				October 3, 2003
# Whom:					Bruno Van Den Bossche <bruno.van.den.bossche@pandora.be>
#
# $FreeBSD$
#

PORTNAME=	pmd
PORTVERSION=	1.1.2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pmd
PKGNAMEPREFIX=	eclipse-
DISTNAME=	pmd-eclipse-bin-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.org
COMMENT=	Scan Java source code and look for potential problems

BROKEN=		It is too hard to adopt Eclipse 3.0.

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

CPIO?=		cpio --quiet -pdmu -R

PLUGIN_DIR=	"net.sourceforge.pmd.eclipse_${PORTVERSION}"

PLIST_SUB+=	PLUGIN_DIR="${PLUGIN_DIR}"

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${MKDIR} ${PREFIX}/eclipse/plugins
		@${MKDIR} ${PREFIX}/eclipse/plugins/${PLUGIN_DIR}
		cd ${WRKSRC}/${PLUGIN_DIR} && ${FIND} . \
		  | ${CPIO} ${SHAREOWN}:${SHAREGRP} \
		  ${PREFIX}/eclipse/plugins/${PLUGIN_DIR}

.include <bsd.port.mk>
