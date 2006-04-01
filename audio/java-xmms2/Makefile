# New ports collection makefile for:	java-xmms2
# Date created:				18 Mar 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

CATEGORIES=	audio java
PKGNAMEPREFIX=	java-

MAINTAINER=	alex@foxybanana.com
COMMENT=	Java Bindings for XMMS2

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

MASTERDIR=	${.CURDIR}/../xmms2

USE_JAVA=	yes
JAVA_VERSION=	1.4+

PLIST_FILES=	${JAVAJARDIR}/xmms2java.jar

SCONS_TARGET=	src/clients/lib/java/libxmms2java.so src/clients/lib/java/xmms2java.jar

XMMS2_SLAVE=	java

do-install:
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} src/clients/lib/java/xmms2java.jar \
	${JAVAJARDIR}/xmms2java.jar

.include "${MASTERDIR}/Makefile"
