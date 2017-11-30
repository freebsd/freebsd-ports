# Created by: ijliao
# $FreeBSD$

PORTNAME=	jcommon
PORTVERSION=	1.0.23
CATEGORIES=	java devel
MASTER_SITES=	SF/jfreechart/3.%20JCommon/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of useful classes used by JFreeChart and JFreeReport

LICENSE=	LGPL21

BROKEN_armv6=		fails to package: find: *: No such file or directory
BROKEN_armv7=		fails to package: find: *: No such file or directory

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

OPTIONS_DEFINE=	COMPILE DOCS
OPTIONS_DEFAULT=COMPILE
COMPILE_DESC=	Build from source

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPILE}
USE_ANT=	yes
ALL_TARGET=	compile-xml
BUILD_WRKSRC=	${WRKSRC}/ant
.else
NO_BUILD=	yes
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MCOMPILE}
ALL_TARGET+=	javadoc
PORTDOCS=	*
.endif

PLIST_FILES=	%%JAVAJARDIR%%/jcommon.jar %%JAVAJARDIR%%/jcommon-xml.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-xml-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-xml.jar
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MCOMPILE}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/javadoc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
