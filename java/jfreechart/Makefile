PORTNAME=	jfreechart
PORTVERSION=	1.0.17
PORTREVISION=	1
CATEGORIES=	java graphics
MASTER_SITES=	SF/${PORTNAME}/1.%20JFreeChart/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Free Java class library for generating charts
WWW=		http://www.jfree.org/jfreechart/index.php

LICENSE=	LGPL21

RUN_DEPENDS=	${JAVALIBDIR}/jcommon.jar:java/jcommon

OPTIONS_DEFINE=	COMPILE DOCS
OPTIONS_DEFAULT=COMPILE

COMPILE_DESC=	Build from source

COMPILE_USES=		java:ant,run
COMPILE_USES_OFF=	java
COMPILE_USE=	LOCALE=en_US.UTF-8
COMPILE_ALL_TARGET=	compile
COMPILE_VARS_OFF=	NO_BUILD=yes
COMPILE_MAKE_ARGS+=	-Dsrc.version=1.8 -Dtarget.version=1.8

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPILE}
BUILD_WRKSRC=	${WRKSRC}/ant
.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
PORTDOCS=	*
.endif
.endif

PLIST_FILES=	%%JAVAJARDIR%%/jfreechart.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MCOMPILE}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/javadoc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
