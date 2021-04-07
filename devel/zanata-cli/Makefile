PORTNAME=	zanata-cli
PORTVERSION=	4.6.2
DISTVERSIONSUFFIX=	-dist
CATEGORIES=	devel java
MASTER_SITES=	https://repo.maven.apache.org/maven2/org/zanata/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Zanata Java command line client

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USE_JAVA=	yes
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB=	ZANATA_VERSION=${PORTVERSION}
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's#REPO=$$#REPO=${JAVASHAREDIR}/zanata-cli/lib#' \
		${WRKSRC}/bin/zanata-cli

do-install:
	${INSTALL_DATA} ${WRKSRC}/bin/zanata-cli ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/zanata-cli/lib
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${JAVASHAREDIR}/zanata-cli/lib

.include <bsd.port.mk>
