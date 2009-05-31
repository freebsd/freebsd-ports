# New ports collection makefile for:	Adobe Flex SDK
# Date created:		18 Oct 2007
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flex-sdk
PORTVERSION=	2.0.1.194515
CATEGORIES=	devel java
MASTER_SITES=	#
DISTFILES=	flex_sdk_2_194515.zip

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Adobe Flex SDK

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

RESTRICTED=	Need agreement before download

CONFLICTS=	ja-flex-sdk-2.* flex-sdk-3.*
NO_LATEST_LINK=	YES
USE_ZIP=	YES
USE_JAVA=	YES
JAVA_VERSION=	1.4+
WRKSRC=		${WRKDIR}
DOWNLOAD_URL=	http://labs.adobe.com/technologies/flex/sdk/flex2sdk.html
SUB_FILES=	asdoc.sh compc.sh fdb.sh mxmlc.sh
NO_BUILD=	YES
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST=	PORTNAME=${PORTNAME}

.include <bsd.port.pre.mk>

.for i in ${DISTFILES}
.if !exists(${DISTDIR}/${i})
ECHO_MSG=/usr/bin/printf
IGNORE=		:\n\
You must fetch the distribution manually.\n\n\
Please access \n\
\n\
 ${DOWNLOAD_URL}\n\
\n\
with a web browser.  Please place the downloaded ${i} \n\
in ${DISTDIR}.\n\n
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
