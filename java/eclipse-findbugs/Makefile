# New ports collection makefile for:	findbugs eclipse plugin
# Date created:		Dom  1 Abr 2007 22:42:25 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	findbugs
DISTVERSION=	1.2.0.20070317
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	edu.umd.cs.findbugs.plugin.eclipse_${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	An Eclipse plug-in that provides FindBugs support

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

do-install:
		@${MKDIR} ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC} ${PREFIX}/eclipse/plugins
		@(cd ${WRKDIR}; ${FIND} -s $$(${BASENAME} ${WRKSRC}) -not -type d) \
			| ${SED} -ne 's,^,eclipse/plugins/,p' > ${TMPPLIST}
		@(cd ${WRKDIR}; ${FIND} -s -d $$(${BASENAME} ${WRKSRC}) -type d) \
			| ${SED} -ne 's,^,@dirrm eclipse/plugins/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
