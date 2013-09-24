# $FreeBSD$

PORTNAME=	jna
PORTVERSION=	4.0
CATEGORIES=	devel java
MASTER_SITES=	GH

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Java access to native shared libraries

USES=		gmake
USE_GCC=	any
USE_ANT=	yes
USE_JAVA=	1.4+
USE_XORG=	x11 xt
MAKE_ARGS=	-DCC=${CC} -DLD=${LD}
MAKE_ENV+=      ANT_OPTS=-Drelease

USE_GITHUB=	yes
GH_ACCOUNT=	twall
GH_TAG=		${PORTVERSION}
GH_COMMIT=	9b7ba38

PLIST_FILES=	%%JAVAJARDIR%%/jna-platform.jar \
		%%JAVAJARDIR%%/jna.jar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	javadoc platform-${PORTVERSION:L}.0-javadoc.jar
.endif

.if ${ARCH} == "i386"
ARCH=	x86
.elif ${ARCH} == "amd64"
ARCH=	x86-64
.endif

NO_STAGE=	yes

post-patch:
	@${CHMOD} 755 ${WRKSRC}/native/libffi/configure
	@${CHMOD} 755 ${WRKSRC}/native/libffi/install-sh

post-build-script:
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${ANT} javadoc
.endif

do-install:
	@${INSTALL_DATA} ${WRKSRC}/build/freebsd-${ARCH}.jar ${JAVAJARDIR}/jna-platform.jar
	@${INSTALL_DATA} ${WRKSRC}/build/jna.jar ${JAVAJARDIR}/jna.jar
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} javadoc ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/platform-${PORTVERSION:L}.0-javadoc.jar ${DOCSDIR}
.endif

.include <bsd.port.mk>
