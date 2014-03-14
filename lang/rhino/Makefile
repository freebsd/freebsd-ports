# Created by: Nicola Vitale	<nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rhino
DISTVERSION=	1_7R4
CATEGORIES=	lang java
MASTER_SITES=	http://cloud.github.com/downloads/mozilla/rhino/:rhino \
		LOCAL/nivit/${PORTNAME}/:swingex \
		${MASTER_SITE_APACHE}:xmlbeans
MASTER_SITE_SUBDIR=	xmlbeans/binaries/:xmlbeans
DISTFILES=	${PORTNAME}${DISTVERSION}.zip:rhino \
		src.zip:swingex \
		xmlbeans-2.5.0.zip:xmlbeans
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}${DISTVERSION}.zip

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	An implementation of JavaScript written in Java

LICENSE=	MPL

ALL_TARGET=	jar

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

JAVA_VERSION=	1.6+

MAKE_ARGS=	-Dxmlbeans.url=file://${DISTDIR}/${DIST_SUBDIR}/xmlbeans-2.5.0.zip \
		-Dswing-ex-url=file://${DISTDIR}/${DIST_SUBDIR}/src.zip

OPTIONS_DEFINE=	LINEDIT
LINEDIT_DESC=	Enable line editing in the Rhino shell

OPTIONS_DEFAULT=	LINEDIT

USES=		zip

NO_STAGE=	yes
.include <bsd.port.options.mk>

RHINOJAR=	${DATADIR}/${PORTNAME}.jar

SUB_FILES=	rhinoc rhinodbg rhinosh
SUB_LIST=	RHINOJAR=${RHINOJAR} JLINEJAR="${JLINEJAR}"

USE_ANT=	yes
USE_JAVA=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}${DISTVERSION}

do-install:
	@${MKDIR} ${DATADIR}; \
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}${DISTVERSION}/js.jar  ${RHINOJAR}; \
	RHINOSCRIPTS="${SUB_FILES}"; \
	for RHINOSCRIPT in $${RHINOSCRIPTS}; do \
	${INSTALL_SCRIPT} ${WRKDIR}/$${RHINOSCRIPT} ${PREFIX}/bin/; \
	done

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLINEDIT}
JLINEJAR=	${JAVAJARDIR}/jline.jar
RUN_DEPENDS+=	${JLINEJAR}:${PORTSDIR}/devel/jline
.else
JLINEJAR=""
.endif

.include <bsd.port.post.mk>
