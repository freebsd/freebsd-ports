# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt-java
PORTVERSION=	0.4.9
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	http://libvirt.org/sources/java/ \
		ftp://libvirt.org/libvirt/java/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Java bindings for Libvirt virtualization API

LICENSE=	MIT

LIB_DEPENDS=	virt.1001:${PORTSDIR}/devel/libvirt
BUILD_DEPENDS=	jna>=3.2.7:${PORTSDIR}/devel/jna \
		junit>=4.8.2:${PORTSDIR}/java/junit

USE_JAVA=	YES
JAVA_VERSION=	1.6+
USE_ANT=	YES

PLIST_FILES=	%%JAVAJARDIR%%/libvirt-${PORTVERSION}.jar
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/java|${JAVAJARDIR}|' \
		${WRKSRC}/build.properties

.include <bsd.port.options.mk>

post-build-script:
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && \
		${ANT} docs
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/libvirt-${PORTVERSION}.jar ${JAVAJARDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/target/javadoc && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

.include <bsd.port.mk>
