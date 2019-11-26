# Created by: ijliao
# $FreeBSD$

PORTNAME=	jfreechart
PORTVERSION=	1.0.17
CATEGORIES=	java graphics
MASTER_SITES=	SF/${PORTNAME}/1.%20JFreeChart/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Free Java class library for generating charts

LICENSE=	LGPL21

RUN_DEPENDS=	${JAVALIBDIR}/jcommon.jar:java/jcommon

USE_JAVA=	yes

OPTIONS_DEFINE=	COMPILE DOCS
OPTIONS_DEFAULT=COMPILE
COMPILE_DESC=	Build from source

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPILE}
USE_ANT=	yes
USE_LOCALE=	en_US.UTF-8
ALL_TARGET=	compile
BUILD_WRKSRC=	${WRKSRC}/ant
.else
NO_BUILD=	yes
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MCOMPILE}
ALL_TARGET+=	javadoc
PORTDOCS=	*
.endif

PLIST_FILES=	%%JAVAJARDIR%%/jfreechart.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MCOMPILE}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/javadoc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
