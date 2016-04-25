# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	intellij-pty4j
PORTVERSION=	0.5
CATEGORIES=	java devel

MAINTAINER=	t@tobik.me
COMMENT=	FreeBSD-compatible replacement for IntelliJ's bundled Pty4J

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

USE_GITHUB=	yes
GH_ACCOUNT=	idea4bsd
GH_PROJECT=	pty4j
GH_TAGNAME=	5d29b891bca0ddf122fc51e3ce066fe421b47b54

USES=	gmake

.include "${.CURDIR}/../intellij/common.mk"

PLIST_FILES=	${IDEA_HOME}/lib/pty4j-0.5.jar

.include <bsd.port.options.mk>

# The directory we need to install Pty4J's native library in depends
# on the install target's architecture.  We rebuild libpty.so instead
# of using one of the bundled ones which are FreeBSD 10.x only.
.if ${ARCH} == "amd64"
PTY4J_ARCH=	x86_64
.elif ${ARCH} == "i386"
PTY4J_ARCH=	x86
.else
PTY4J_ARCH=
.endif

.if ${PTY4J_ARCH} != ""
# Despite what the name might suggest using the linux_x86_64 target
# will always build libpty.so for the native platform.
BUILD_WRKSRC=	${WRKSRC}/native
MAKEFILE=	Makefile_freebsd
ALL_TARGET=	linux_x86_64
PLIST_FILES+=	${IDEA_HOME}/lib/libpty/freebsd/${PTY4J_ARCH}/libpty.so
.else
# If native Pty4J support is missing IntelliJ IDEA will still work but
# without the ability to open terminals.
NO_BUILD=	yes
.endif

do-install:
.if ${PTY4J_ARCH} != ""
	${MKDIR} ${STAGEDIR}${IDEA_HOME}/lib/libpty/freebsd/${PTY4J_ARCH}
# See above why we always use freebsd/x86_64/ here
	${INSTALL_LIB} ${WRKSRC}/os/freebsd/x86_64/libpty.so ${STAGEDIR}${IDEA_HOME}/lib/libpty/freebsd/${PTY4J_ARCH}/
.endif
	${INSTALL_DATA} ${WRKSRC}/build/pty4j-0.5.jar ${STAGEDIR}${IDEA_HOME}/lib/pty4j-0.5.jar

.include <bsd.port.mk>
