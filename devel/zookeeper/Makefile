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
MASTER_SITES=	http://apache.mesi.com.ar/zookeeper/stable/

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	A Coordination Service for Distributed Applications

LIB_DEPENDS=	cppunit:${PORTSDIR}/devel/cppunit
BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		libtool:${PORTSDIR}/devel/libtool \

.if defined(WITH_PYTHON)
BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python
.endif

RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_JAVA=	yes
JAVA_VERSION=	1.7
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes

USE_AUTOTOOLS=	autoconf

CONFLICTS=	zookeeper-devel-[0-9]*

PYTHON_WRKSRC=	${WRKSRC}/src/contrib/zkpython
CONFIGURE_WRKSRC=${WRKSRC}/src/c

OPTIONS=	C "Build C library bindings" on \
		PYTHON "Build Python library bindings" on

.include <bsd.port.pre.mk>

.if defined(WITH_C)
run-autotools:	run-autotools-autoreconf

run-autotools-autoreconf:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -if
.endif

do-build:
.if defined(WITH_C)
	@cd ${CONFIGURE_WRKSRC} && \
	${MAKE}
.endif
.if defined(WITH_PYTHON)
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
	@${INSTALL} ${FILESDIR}/zookeeper ${PREFIX}/etc/rc.d/
.if defined(WITH_C)
	@cd ${BUILD_WRKSRC} && \
	make install
.endif
.if defined(WITH_PYTHON)
	@cd ${PYTHON_WRKSRC} && \
	ant install
.endif

.include <bsd.port.post.mk>
