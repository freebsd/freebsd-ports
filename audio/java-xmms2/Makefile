# New ports collection makefile for:	java-xmms2
# Date created:				18 Mar 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	audio java
PKGNAMEPREFIX=	java-

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Java Bindings for XMMS2

BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13 \
		${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2
RUN_DEPENDS+=	${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2

USE_JAVA=	yes
JAVA_VERSION=	1.4+

USE_LDCONFIG=	yes
PLIST=		${.CURDIR}/pkg-plist

SCONS_BUILDENV=	JAVA_HOME=${JAVA_HOME}
SCONS_TARGET=	src/clients/lib/java

XMMS2_SLAVE=	java

# Crazy workaround for a bug introduced sometime after DrDoolittle that
# causes the java bindings to not be built completely on the first
# run of scons.

do-build:
	@cd ${WRKSRC} && \
	${SETENV} ${SCONS_BUILDENV} ${SCONS_BIN} ${SCONS_ENV} ${SCONS_ARGS} \
	${SCONS_TARGET}
	@cd ${WRKSRC} && \
	${SETENV} ${SCONS_BUILDENV} ${SCONS_BIN} ${SCONS_ENV} ${SCONS_ARGS} \
	${SCONS_TARGET}

do-install:
	@cd ${WRKSRC} && ${INSTALL_DATA} src/clients/lib/java/xmms2java.jar \
	${JAVAJARDIR}/xmms2java.jar
	@cd ${WRKSRC} && ${INSTALL_DATA} src/clients/lib/java/libxmms2java.so \
	${PREFIX}/lib/libxmms2java.so

.include "${MASTERDIR}/Makefile"
