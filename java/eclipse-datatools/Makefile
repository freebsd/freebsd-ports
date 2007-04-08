# New ports collection makefile for:	eclipse-datatools
# Date created:		Dom  1 Abr 2007 22:18:17 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	datatools
PORTVERSION=	0.9.1
CATEGORIES=	java devel databases
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	dtp_${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Datatools for eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/features/org.eclipse.emf_2.2.1.v200609210005/feature.xml:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/eclipse/features/org.eclipse.gef_3.2.2.v20070208/feature.xml:${PORTSDIR}/java/eclipse-gef

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse
		@(cd ${WRKSRC}; ${FIND} -s eclipse/features eclipse/plugins -not -type d) >> ${TMPPLIST}
		@(cd ${WRKSRC}; ${FIND} -s -d eclipse/features eclipse/plugins -type d) \
			| ${GREP} -vE 'eclipse/plugins$$|eclipse/features$$' \
			| ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST}

.include <bsd.port.pre.mk>

.include "${.CURDIR}/Makefile.master-sites"

.include <bsd.port.post.mk>
