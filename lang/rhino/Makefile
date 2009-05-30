# New ports collection makefile for:	rhino
# Date created:		2008-01-26
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rhino
DISTVERSION=	1_7R2
PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	lang java
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla.org/js/:rhino \
		http://java.sun.com/products/jfc/tsc/articles/treetable2/downloads/:swingex \
		http://www.apache.org/dist/xmlbeans/binaries/:xmlbeans
MASTER_SITE_SUBDIR=	xmlbeans/binaries/:xmlbeans
DISTFILES=	${PORTNAME}${DISTVERSION}.zip:rhino \
		src.zip:swingex \
		xmlbeans-2.2.0.zip:xmlbeans
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}${DISTVERSION}.zip

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	An implementation of JavaScript written in Java

OPTIONS=	LINEDIT	"Enable line editing in the Rhino shell" on

ALL_TARGET=	jar

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

JAVA_VERSION=	1.5+

MAKE_ARGS=	-Dxmlbeans.url=file://${DISTDIR}/${DIST_SUBDIR}/xmlbeans-2.2.0.zip \
		-Dswing-ex-url=file://${DISTDIR}/${DIST_SUBDIR}/src.zip

RHINOJAR=	${DATADIR}/${PORTNAME}.jar

SUB_FILES=	rhinoc rhinodbg rhinosh
SUB_LIST=	RHINOJAR=${RHINOJAR} JLINEJAR=":${JLINEJAR}"

USE_ANT=	yes
USE_JAVA=	yes
USE_ZIP=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}${DISTVERSION}

do-install:
	@${MKDIR} ${DATADIR}; \
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}${DISTVERSION}/js.jar  ${RHINOJAR}; \
	RHINOSCRIPTS="${SUB_FILES}"; \
	for RHINOSCRIPT in $${RHINOSCRIPTS}; do \
	${INSTALL_SCRIPT} ${WRKDIR}/$${RHINOSCRIPT} ${PREFIX}/bin/; \
	done

.include <bsd.port.pre.mk>

.if defined(WITH_LINEDIT)
JLINEJAR=	${JAVAJARDIR}/jline.jar
RUN_DEPENDS+=	${JLINEJAR}:${PORTSDIR}/devel/jline
.else
JLINEJAR=""
.endif

.include <bsd.port.post.mk>
