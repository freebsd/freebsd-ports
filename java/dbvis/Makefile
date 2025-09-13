PORTNAME=	dbvis
DISTVERSION=	25.2.3
CATEGORIES=	java databases
MASTER_SITES=	https://www.dbvis.com/product_download/${PORTNAME}-${DISTVERSION}/media/ \
		https://storage.googleapis.com/${PORTNAME}-download/product_download/${PORTNAME}-${DISTVERSION}/media/
DISTNAME=	dbvis_linux_${DISTVERSION:S/./_/g}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	DbVisualizer database tool
WWW=		https://www.dbvis.com/

LICENSE=	DbVisualizer_EULA
LICENSE_NAME=	End-User License Agreement for DbVisualizer
LICENSE_TEXT=	Full license can be found at https://www.dbvis.com/eula/
# Redistribution is not permitted
LICENSE_PERMS=	auto-accept

USES=		java
JAVA_VERSION=	21+
JAVA_VENDOR=	openjdk

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/DbVisualizer
PLIST_FILES=	bin/dbvis

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! ( -name dbvis -o -name dbviscmd.sh -o -name dbvisgui.sh )")
	${INSTALL_SCRIPT} ${WRKSRC}/dbvis \
			  ${WRKSRC}/dbviscmd.sh	\
			  ${WRKSRC}/dbvisgui.sh	${STAGEDIR}${DATADIR}
	${RLN} ${STAGEDIR}${DATADIR}/dbvis	${STAGEDIR}${PREFIX}/bin/dbvis

post-install:
	${FIND} ${STAGEDIR}${DATADIR} -not -type d \
	  | ${SED} -ne 's,^${STAGEDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	${FIND} -d ${STAGEDIR}${DATADIR} -type d -empty \
	  | ${SED} -ne 's,^${STAGEDIR}${PREFIX}/,@dir ,p' >> ${TMPPLIST}

.include <bsd.port.mk>
