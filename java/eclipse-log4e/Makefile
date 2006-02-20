# New ports collection makefile for:	eclipse-log4e
# Date created:				August 30, 2004
# Whom:					sugimura@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	log4e
PORTVERSION=	1.1.6
CATEGORIES=	java
MASTER_SITES=	http://log4e.jayefem.de/download/eclipse3/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	de.jayefem.${PORTNAME}_free_${PORTVERSION}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	eclipse

MAINTAINER=	sugimura@jp.FreeBSD.ORG
COMMENT=	Eclipse plugin to use logger easily in Java projects

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} -p ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse
		@(cd ${WRKSRC}; ${FIND} -s features plugins -not -type d) \
			| ${SED} -ne 's,^,eclipse/,p' >> ${TMPPLIST}
		@(cd ${WRKSRC}; ${FIND} -s -d features plugins -type d) \
			| ${GREP} -vE 'plugins$$|features$$' \
			| ${SED} -ne 's,^,@dirrm eclipse/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
