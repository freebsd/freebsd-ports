# Created by: Anton Yudin (<contact@toha.org.ua>)
# $FreeBSD$

PORTNAME=	dbvis
PORTVERSION=	7.1
CATEGORIES=	java devel
MASTER_SITES=	http://www.dbvis.com/product_download/${PORTNAME}-${PORTVERSION}/media/
DISTNAME=	dbvis_unix_${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DbVisualizer database tool

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
RESTRICTED=	Redistribution is not permitted

PLIST_FILES=	bin/dbvis
WRKSRC=		${WRKDIR}/DbVisualizer-${PORTVERSION}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/dbvis ${STAGEDIR}${PREFIX}/bin/dbvis
	${CHMOD} a+x ${STAGEDIR}${DATADIR}/dbvis

post-install:
	${FIND} ${STAGEDIR}${DATADIR} -not -type d \
	  | ${SED} -ne 's,^${STAGEDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	${FIND} -d ${STAGEDIR}${DATADIR} -type d \
	  | ${SED} -ne 's,^${STAGEDIR}${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}

.include <bsd.port.mk>
