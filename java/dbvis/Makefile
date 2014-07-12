# Created by: Anton Yudin (<contact@toha.org.ua>)
# $FreeBSD$

PORTNAME=	dbvis
PORTVERSION=	9.1.6
CATEGORIES=	databases java
MASTER_SITES=	http://www.dbvis.com/product_download/${PORTNAME}-${PORTVERSION}/media/
DISTNAME=	dbvis_unix_${PORTVERSION:S/./_/g}

MAINTAINER=	jim@ohlste.in
COMMENT=	DbVisualizer database tool

LICENSE=	DbVisualizer_EULA
LICENSE_NAME=	End-User License Agreement for DbVisualizer
LICENSE_TEXT=	Full license can be found at http://www.dbvis.com/eula/
LICENSE_PERMS=	auto-accept

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_VENDOR=	openjdk
NO_BUILD=	yes
RESTRICTED=	Redistribution is not permitted

PLIST_FILES=	bin/dbvis
WRKSRC=		${WRKDIR}/DbVisualizer

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ../share/dbvis dbvis
	${CHMOD} a+x ${STAGEDIR}${DATADIR}/dbvis

post-install:
	${FIND} ${STAGEDIR}${DATADIR} -not -type d \
	  | ${SED} -ne 's,^${STAGEDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	${FIND} -d ${STAGEDIR}${DATADIR} -type d \
	  | ${SED} -ne 's,^${STAGEDIR}${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}

.include <bsd.port.mk>
