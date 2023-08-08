PORTNAME=	pty4j
PORTVERSION=	0.12.13
CATEGORIES=	devel java
PKGNAMEPREFIX=	jetbrains-
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	Pty4J's native library
WWW=		https://github.com/JetBrains/pty4j

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	JetBrains
GH_PROJECT=	pty4j
GH_TAGNAME=	32b777311438b7a9c5de4cf56cde269ffd27e65e

DATADIR=	${PREFIX}/share/jetbrains/${PORTNAME}

ALL_TARGET=	linux_x86_64
BUILD_WRKSRC=	${WRKSRC}/native
MAKEFILE=	Makefile_freebsd
PLIST_FILES=	share/jetbrains/${PORTNAME}/${ARCH}/libpty.so

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/${ARCH}
	${INSTALL_LIB} \
		${WRKSRC}/os/freebsd/x86-64/libpty.so \
		${STAGEDIR}${DATADIR}/${ARCH}

.include <bsd.port.mk>
