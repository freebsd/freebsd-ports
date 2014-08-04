# $FreeBSD$

PORTNAME=	flex_compiler_shell
PORTVERSION=	0.20070123
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	http://download.macromedia.com/pub/labs/flex_compiler_shell/
DISTNAME=	flex_compiler_shell_012307

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adobe Flex Compiler Shell

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		mxmlc:${PORTSDIR}/devel/flex-sdk2

RESTRICTED=	Redistribution is not allowed
CONFLICTS=	flex-sdk-3.*

USES=		zip
USE_JAVA=	YES
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}
NO_BUILD=	YES
SUB_FILES=	fcsh

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fcsh ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/fcsh.jar ${STAGEDIR}${JAVAJARDIR}/flex-sdk/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FlexCompilerShell-license.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
