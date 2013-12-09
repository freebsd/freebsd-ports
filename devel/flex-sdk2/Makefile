# $FreeBSD$

PORTNAME=	flex-sdk
PORTVERSION=	2.0.1.194515
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	#
DISTFILES=	flex_sdk_2_194515.zip
PKGNAMESUFFIX=	2

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Adobe Flex SDK

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

RESTRICTED=	Need agreement before download

CONFLICTS=	ja-flex-sdk-2.* flex-sdk3-3.* flex-sdk-4.*
USE_ZIP=	YES
USE_JAVA=	YES
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}
DOWNLOAD_URL=	http://labs.adobe.com/technologies/flex/sdk/flex2sdk.html
SUB_FILES=	asdoc.sh compc.sh fdb.sh mxmlc.sh
NO_BUILD=	YES
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST=	PORTNAME=${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.for i in ${DISTFILES}
.if !exists(${DISTDIR}/${i})
IGNORE=	you must fetch the distribution manually. Please access\
${DOWNLOAD_URL} with a web browser.  Please place the downloaded\
${i} in ${DISTDIR} and re-run make
.endif
.endfor

do-install:
.for i in asdoc compc fdb mxmlc
	${INSTALL_SCRIPT} ${WRKSRC}/${i}.sh ${PREFIX}/bin/${i}
.endfor

	${MKDIR} ${JAVAJARDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${JAVAJARDIR}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/asdoc/lib/*.jar ${JAVAJARDIR}/${PORTNAME}/

	${MKDIR} ${DATADIR}/frameworks
	${CP} -r ${WRKSRC}/frameworks/ ${DATADIR}/frameworks/

	${MKDIR} ${DATADIR}/asdoc/templates
	${CP} -r ${WRKSRC}/asdoc/templates/ ${DATADIR}/asdoc/templates/

	${MKDIR} ${DATADIR}/resources
	${CP} -r ${WRKSRC}/resources/ ${DATADIR}/resources/

	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/*.htm ${DOCSDIR}/

.include <bsd.port.post.mk>
