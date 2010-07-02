# Ports collection makefile for:	DbVisualizer
# Date created:			April 08, 2007
# Whom:				Anton Yudin (<contact@toha.org.ua>)
#
# $FreeBSD$
#

PORTNAME=	dbvis
PORTVERSION=	7.1
CATEGORIES=	java devel
MASTER_SITES=	http://www.dbvis.com/product_download/${PORTNAME}-${PORTVERSION}/media/
DISTNAME=	dbvis_unix_${PORTVERSION:S/./_/g}

MAINTAINER=	contact@toha.org.ua
COMMENT=	DbVisualizer database tool

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
RESTRICTED=	Redistribution is not permitted

PLIST_FILES=	bin/dbvis
WRKSRC=		DbVisualizer-${PORTVERSION}

do-install:
	cd ${WRKDIR}/${WRKSRC} \
	  && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \; \
	  && ${LN} -s ${DATADIR}/dbvis ${PREFIX}/bin/dbvis \
	  && ${CHMOD} a+x ${DATADIR}/dbvis

post-install:
	cd ${WRKDIR}/${WRKSRC} && \
	${FIND} ${DATADIR} -not -type d \
	  | ${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	${FIND} -d ${DATADIR} -type d \
	  | ${SED} -ne 's,^${PREFIX},@dirrm ,p' >> ${TMPPLIST}

.include <bsd.port.mk>
