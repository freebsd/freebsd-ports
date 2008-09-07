# New ports collection makefile for:	Flex Compiler Shell
# Date created:		1 Dec 2007
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flex_compiler_shell
PORTVERSION=	0.20070123
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	http://download.macromedia.com/pub/labs/flex_compiler_shell/
DISTNAME=	flex_compiler_shell_012307

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Adobe Flex Compiler Shell

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		mxmlc:${PORTSDIR}/devel/flex-sdk2

RESTRICTED=	Redistribution is not allowed
CONFLICTS=	flex-sdk-3.*

USE_ZIP=	YES
USE_JAVA=	YES
JAVA_VERSION=	1.4+
WRKSRC=		${WRKDIR}
NO_BUILD=	YES
SUB_FILES=	fcsh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fcsh ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/fcsh.jar ${JAVAJARDIR}/flex-sdk/
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FlexCompilerShell-license.txt ${DOCSDIR}/

.include <bsd.port.mk>
