# $FreeBSD$

PORTNAME=	flex-sdk
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	japanese devel java
MASTER_SITES=	#
DISTFILES=	flex_sdk_2_hf1.zip flex_sdk_2_ja.zip

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Adobe Flex SDK (with Japanese language)

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

RESTRICTED=	Need agreement before download

CONFLICTS=	flex-sdk-2.* flex-sdk-3.* flex-sdk-4.*
USES=		zip
USE_JAVA=	YES
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}
DOWNLOAD_URL=	http://www.adobe.com/products/flex/sdk/
SUB_FILES=	asdoc.sh compc.sh fdb.sh mxmlc.sh
NO_BUILD=	YES
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST=	PORTNAME=${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.for i in ${DISTFILES}
.if !exists(${DISTDIR}/${i})
IGNORE=	you must fetch the distribution manually.\
Please access ${DOWNLOAD_URL} with a web browser.\
Please place the downloaded ${i} in ${DISTDIR} and\
re-run make
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

	${MKDIR} ${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/samples/ ${EXAMPLESDIR}/

	${MKDIR} ${EXAMPLESDIR}/ja
	${CP} -r ${WRKSRC}/samples_ja/ ${EXAMPLESDIR}/ja/

	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/*.htm ${DOCSDIR}/

.include <bsd.port.post.mk>
