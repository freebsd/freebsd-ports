# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mkgmap
PORTVERSION=	r3598
CATEGORIES=	astro converters java
MASTER_SITES=	http://www.mkgmap.org.uk/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert OpenStreetMap data into a Garmin format

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENCE

NO_BUILD=	yes
NO_ARCH=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+

SUB_FILES=	${PORTNAME}.sh

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}/lib/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
