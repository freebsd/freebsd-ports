# New ports collection makefile for:	java-xmms2
# Date created:				18 Mar 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTREVISION=	2
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

BROKEN=	Requires Java 1.6 and are no longer included with xmms2
XMMS2_SLAVE=	java

.include "${MASTERDIR}/Makefile"
