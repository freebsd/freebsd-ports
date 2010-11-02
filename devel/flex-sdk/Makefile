# New ports collection makefile for:	Adobe Flex SDK
# Date created:		18 Oct 2007
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flex-sdk
PORTVERSION=	4.1.0.16076
CATEGORIES=	devel java
MASTER_SITES=	http://fpdownload.adobe.com/pub/flex/sdk/builds/flex4/
DISTFILES=	flex_sdk_${PORTVERSION}_mpl.zip

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Adobe Flex SDK

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

CONFLICTS=	ja-flex-sdk-2.* flex-sdk-2.* flex-sdk-3.*
USE_ZIP=	YES
USE_DOS2UNIX=	YES
USE_JAVA=	YES
JAVA_VERSION=	1.4+
WRKSRC=		${WRKDIR}
SUB_FILES=	${SCRIPTS:C/\$/.sh/g}
NO_BUILD=	YES
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST=	PORTNAME=${PORTNAME}
SCRIPTS=	aasdoc acompc amxmlc asdoc compc copylocale digest \
		fcsh fdb mxmlc optimizer

.include <bsd.port.pre.mk>

post-extract:
	${RM} ${WRKSRC}/bin/*.bat ${WRKSRC}/bin/*.exe
	${FIND} ${WRKSRC} -print0 -type f | ${XARGS} -0 ${CHMOD} og+r
	${FIND} ${WRKSRC} -print0 -type f -perm +0111 | ${XARGS} -0 ${CHMOD} og+rx
	${FIND} ${WRKSRC} -print0 -type d | ${XARGS} -0 ${CHMOD} og+rx

do-install:
.for i in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${i}.sh ${PREFIX}/bin/${i}
.endfor

	${MKDIR} ${JAVAJARDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${JAVAJARDIR}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/ant/lib/*.jar ${JAVAJARDIR}/${PORTNAME}/

	${MKDIR} ${DATADIR}/frameworks
	${CP} -r ${WRKSRC}/frameworks/ ${DATADIR}/frameworks/

	${MKDIR} ${DATADIR}/asdoc/templates
	${CP} -r ${WRKSRC}/asdoc/templates/ ${DATADIR}/asdoc/templates/

	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/*.htm ${DOCSDIR}/

.include <bsd.port.post.mk>
