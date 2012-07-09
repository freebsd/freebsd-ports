# New ports collection makefile for:	zookeeper
# Date created: 6 July 2012
# Whom: gnn@freebsd.org
#
# $FreeBSD$
#
# For more information, please read Makefile.doc
#

PORTNAME=	zookeeper
PORTVERSION=	3.3.5
CATEGORIES=	devel java
MASTER_SITES=	http://apache.mesi.com.ar/zookeeper/stable/ \
	http://www.trieuvan.com/apache/zookeeper/stable/

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	A Coordination Service for Distributed Applications

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant
LIB_DEPENDS=	cppunit:${PORTSDIR}/devel/cppunit
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	C PYTHON
C_DESC=	Build C library bindings
OPTIONS_DEFAULT=	C PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.7
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes
USE_RC_SUBR=	zookeeper

USE_AUTOTOOLS=	automake autoconf libtool

CONFLICTS=	zookeeper-devel-[0-9]*

PYTHON_WRKSRC=	${WRKSRC}/src/contrib/zkpython
CONFIGURE_WRKSRC=${WRKSRC}/src/c

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MC}
run-autotools:	run-autotools-autoreconf

run-autotools-autoreconf:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -if
.endif

do-build:
.if ${PORT_OPTIONS:MC}
	@cd ${CONFIGURE_WRKSRC} && \
	${MAKE}
.endif
.if ${PORT_OPTIONS:MPYTHON}
	@cd ${PYTHON_WRKSRC} &&\
	ant compile
.endif

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${CP} -Rp ${WRKSRC}/conf ${PREFIX}/${PORTNAME}
	@${CP} -Rp ${WRKSRC}/bin ${PREFIX}/${PORTNAME}
	@${CP} -Rp ${WRKSRC}/lib ${PREFIX}/${PORTNAME}
	@${CP} -Rp ${WRKSRC}/docs ${PREFIX}/${PORTNAME}
	@${CP} -Rp ${WRKSRC}/*.jar ${PREFIX}/${PORTNAME}
.if ${PORT_OPTIONS:MC}
	@cd ${CONFIGURE_WRKSRC} && \
	${MAKE} install
.endif
.if ${PORT_OPTIONS:MPYTHON}
	@cd ${PYTHON_WRKSRC} && \
	ant install
.endif

.include <bsd.port.post.mk>
