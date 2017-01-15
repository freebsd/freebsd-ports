# $FreeBSD$

PORTNAME=	jna
PORTVERSION=	4.3.0
CATEGORIES=	devel java

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java access to native shared libraries

LICENSE=	LGPL21+ APACHE20
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LICENSE.LGPL
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.AL

USES=		autoreconf:build gmake libtool
USE_ANT=	yes
USE_JAVA=	yes
USE_XORG=	x11 xt
MAKE_ARGS=	-DCC="${CC}" -DLD="${LD}"
MAKE_ENV=	ANT_OPTS=-Drelease -DARCH=${ANT_ARCH}

USE_GITHUB=	yes
GH_ACCOUNT=	twall

PORTDOCS=	javadoc platform-${PORTVERSION}-javadoc.jar
PLIST_FILES=	%%JAVAJARDIR%%/jna-platform.jar \
		%%JAVAJARDIR%%/jna.jar

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
ANT_ARCH=	x86
.elif ${ARCH} == "amd64"
ANT_ARCH=	x86-64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/native/Makefile

post-build-DOCS-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${ANT} javadoc

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-${ANT_ARCH}.jar \
		${STAGEDIR}${JAVAJARDIR}/jna-platform.jar
	${INSTALL_DATA} ${WRKSRC}/build/jna.jar \
		${STAGEDIR}${JAVAJARDIR}/jna.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} javadoc ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/platform-${PORTVERSION}-javadoc.jar \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
