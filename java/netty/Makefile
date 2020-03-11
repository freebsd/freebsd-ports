# Created by: Mikhail T. <michael@fun-box.ru>
# $FreeBSD$

PORTNAME=	netty
PORTVERSION=	4.1.47
DISTVERSIONSUFFIX=	.Final
CATEGORIES=	java devel
MASTER_SITES=	http://dl.bintray.com/netty/downloads/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java NIO client server framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe tar:bzip2
USE_JAVA=	yes

CPE_VENDOR=	netty_project
JAVA_VERSION=	8+
JAVA_EXTRACT=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.Final

DOCDIRS=	javadoc \
		license
DOCFILES=	CONTRIBUTING.md \
		LICENSE.txt \
		NOTICE.txt \
		README.md

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "aarch64"
NETTY_ARCH=	aarch_64
.elif ${ARCH} == "amd64"
NETTY_ARCH=	x86_64
.elif ${ARCH} == "arm6"
NETTY_ARCH=	arm_32
.elif ${ARCH} == "arm7"
NETTY_ARCH=	arm_32
.elif ${ARCH} == "i386"
NETTY_ARCH=	x86_32
.elif ${ARCH} == "powerpc"
NETTY_ARCH=	ppc_32
.elif ${ARCH} == "powerpc64"
NETTY_ARCH=	ppc_64
.elif ${ARCH} == "sparc64"
NETTY_ARCH=	sparc_64
.else
# Default to ${ARCH}
NETTY_ARCH=	${ARCH}
.endif

post-extract:
	(cd ${WRKSRC} && \
		${JAR} xf jar/netty-transport-native-kqueue-${PORTVERSION}.Final-sources.jar)
	(cd ${WRKSRC} && \
		${JAR} xf jar/netty-transport-native-unix-common-${PORTVERSION}.Final-sources.jar)
	@${SED} -e 's!%%NETTY_ARCH%%!${NETTY_ARCH}!g' \
		-e 's!%%JAVA_HOME%%!${JAVA_HOME}!g' \
		${FILESDIR}/Makefile.in > ${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${WRKSRC}/jar/all-in-one/META-INF/native
	@${MV} ${WRKSRC}/libnetty_transport_native_kqueue*.so \
		${WRKSRC}/jar/all-in-one/META-INF/native/
	@(cd ${WRKSRC}/jar/all-in-one && ${JAR} uvf ${PORTNAME}-all-${PORTVERSION}.Final.jar META-INF/native/libnetty_transport_native_kqueue*.so)

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/jar/all-in-one/${PORTNAME}-all-${PORTVERSION}.Final.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar
	${LN} -nfs ${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.for DIR in ${DOCDIRS}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${DIR} ${STAGEDIR}${DOCSDIR}
.endfor
.for FILE in ${DOCFILES}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
