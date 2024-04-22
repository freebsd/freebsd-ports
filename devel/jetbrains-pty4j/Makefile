PORTNAME=	pty4j
PORTVERSION=	0.12.25
CATEGORIES=	devel java
PKGNAMEPREFIX=	jetbrains-
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	Pty4J's native library
WWW=		https://github.com/JetBrains/pty4j

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64le

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	JetBrains
GH_PROJECT=	pty4j
GH_TAGNAME=	673a524230c1a46782211e77b1750877b3aa71f7

DATADIR=	${PREFIX}/share/jetbrains/${PORTNAME}

ALL_TARGET=	linux_${ARCH:S/amd64/x86_64/:S/powerpc64le/ppc64le/}
BUILD_WRKSRC=	${WRKSRC}/native
MAKEFILE=	Makefile_freebsd
PLIST_FILES=	share/jetbrains/${PORTNAME}/${ARCH}/libpty.so

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64le
BINARY_ALIAS=	powerpc64le-linux-gnu-gcc=cc
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/${ARCH}
	${INSTALL_LIB} \
		${WRKSRC}/os/freebsd/${ARCH:S/amd64/x86-64/:S/powerpc64le/ppc64le/}/libpty.so \
		${STAGEDIR}${DATADIR}/${ARCH}

.include <bsd.port.mk>
