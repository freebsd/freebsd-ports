# New ports collection makefile for:	eclipse-sqlexplorer
# Date created:				August 14, 2004
# Whom:					sugimura@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	sqlexplorer
PORTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= eclipsesql
PKGNAMEPREFIX=	eclipse-
DISTNAME=	net.sourceforge.${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	eclipse

MAINTAINER=	sugimura@jp.FreeBSD.ORG
COMMENT=	A visual database query tool for Eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/features/org.eclipse.gef_3.2.2.v20070109/feature.xml:${PORTSDIR}/java/eclipse-gef

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} -p ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
		@(cd ${WRKSRC}; ${FIND} -s plugins -not -type d) \
			| ${SED} -ne 's,^,eclipse/,p' >> ${TMPPLIST}
		@(cd ${WRKSRC}; ${FIND} -s -d plugins -type d) \
			| ${GREP} -vE '^plugins$$' \
			| ${SED} -ne 's,^,@dirrm eclipse/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
