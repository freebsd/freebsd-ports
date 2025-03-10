PORTNAME=	intellij-pty4j
PORTVERSION=	0.12.35
CATEGORIES=	java devel

MAINTAINER=	jinking.this@gmail.com
COMMENT=	Pty4J's native library
WWW=		https://github.com/traff/pty4j

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	gmake

USE_GITHUB=	yes
GH_ACCOUNT=	JetBrains
GH_PROJECT=	pty4j
GH_TAGNAME=	823eadafa619d8726b89675455e07c292718694f

.include "${.CURDIR}/../intellij/common.mk"

.include <bsd.port.options.mk>

# The directory we need to install Pty4J's native library in depends
# on the install target's architecture.  We rebuild libpty.so instead
# of using one of the bundled ones which are FreeBSD 10.x only.
.if ${ARCH} == "amd64"
PTY4J_ARCH=	x86-64
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
# See above why we always use freebsd/x86-64/ here
	${INSTALL_LIB} ${WRKSRC}/os/freebsd/x86-64/libpty.so ${STAGEDIR}${IDEA_HOME}/lib/libpty/freebsd/${PTY4J_ARCH}/
.endif

.include <bsd.port.mk>
