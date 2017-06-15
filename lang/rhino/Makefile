# Created by: Nicola Vitale	<nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rhino
DISTVERSION=	1_7R4
CATEGORIES=	lang java
MASTER_SITES=	GHC \
		LOCAL/nivit/${PORTNAME}/:swingex \
		APACHE/xmlbeans/binaries/:xmlbeans
DISTFILES=	${PORTNAME}${DISTVERSION}.zip \
		src.zip:swingex \
		xmlbeans-2.5.0.zip:xmlbeans
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}${DISTVERSION}.zip

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Implementation of JavaScript written in Java

LICENSE=	MPL

ALL_TARGET=	jar

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

JAVA_VERSION=	1.6+

LINEDIT_DESC=	Enable line editing in the Rhino shell
LINEDIT_RUN_DEPENDS=	${JLINEJAR}:devel/jline
LINEDIT_USE=	java=yes ant=yes

MAKE_ARGS=	-Dxmlbeans.url=file://${DISTDIR}/${DIST_SUBDIR}/xmlbeans-2.5.0.zip \
		-Dswing-ex-url=file://${DISTDIR}/${DIST_SUBDIR}/src.zip

OPTIONS_DEFAULT=	LINEDIT
OPTIONS_DEFINE=	LINEDIT

USES=		zip
USE_GITHUB=	yes
GH_ACCOUNT=	mozilla

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLINEDIT}
JLINEJAR=	${JAVALIBDIR}/jline.jar
.else
JLINEJAR=""
.endif

RHINOJAR=	${DATADIR}/${PORTNAME}.jar

SUB_FILES=	rhinoc rhinodbg rhinosh
SUB_LIST=	RHINOJAR=${RHINOJAR} JLINEJAR="${JLINEJAR}"

WRKSRC=	${WRKDIR}/${PORTNAME}${DISTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}; \
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}${DISTVERSION}/js.jar  ${STAGEDIR}${RHINOJAR}; \
	RHINOSCRIPTS="${SUB_FILES}"; \
	for RHINOSCRIPT in $${RHINOSCRIPTS}; do \
	${INSTALL_SCRIPT} ${WRKDIR}/$${RHINOSCRIPT} ${STAGEDIR}${PREFIX}/bin/; \
	done

.include <bsd.port.mk>
