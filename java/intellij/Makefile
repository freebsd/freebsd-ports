# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

# Based on the devel/intellij port from OpenBSD by
# Vadim Zhukov <zhuk@openbsd.org>

PORTNAME=	intellij
PORTVERSION=	15.0.3
CATEGORIES=	java devel
MASTER_SITES=	https://download.jetbrains.com/idea/:jetbrains \
		http://download.jetbrains.com/idea/:jetbrains \
		GH:pty4j
DISTFILES=	ideaIC-${PORTVERSION}.tar.gz:jetbrains \
		${DISTNAME}.tar.gz:pty4j

MAINTAINER=	t@tobik.me
COMMENT=	IntelliJ IDEA Community Edition

LICENSE=	APACHE20

# Upstream has merged pty4j FreeBSD support but no offical release/tag
# with it yet
USE_GITHUB=	yes
GH_ACCOUNT=	traff
GH_PROJECT=	pty4j
GH_TAGNAME=	335982264104fd4529f2ee75f08d1e1d9f9d544a

USE_JAVA=	yes
JAVA_VERSION=	1.7+

WRKDIST=	${WRKDIR}/idea-IC-143.1821.5

IDEA_HOME=	${PREFIX}/${PORTNAME}

USES=	gmake

PLIST_SUB+=	IDEA_HOME=${IDEA_HOME} \
		PTY4J_ARCH=${PTY4J_ARCH}
SUB_FILES+=	idea idea.desktop
SUB_LIST+=	IDEA_HOME=${IDEA_HOME}

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
.else
# If native Pty4J support is missing IntelliJ IDEA will still work but
# without the ability to open terminals.
NO_BUILD=	yes
.endif

do-install:
	${MKDIR} ${STAGEDIR}${IDEA_HOME}
	@${TAR} -czf - -C ${WRKDIST} . | ${TAR} xzf - -C ${STAGEDIR}${IDEA_HOME}
# Linux/Windows/OS X only so remove them
	@${RM} ${STAGEDIR}${IDEA_HOME}/bin/fsnotifier \
		${STAGEDIR}${IDEA_HOME}/bin/fsnotifier-arm \
		${STAGEDIR}${IDEA_HOME}/bin/fsnotifier64 \
		${STAGEDIR}${IDEA_HOME}/bin/libbreakgen.so \
		${STAGEDIR}${IDEA_HOME}/bin/libbreakgen64.so \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-linux-amd64-0.10.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-linux-i386-0.10.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-osx-amd64-0.10.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-osx-i386-0.10.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-windows-amd64-0.10.jar \
		${STAGEDIR}${IDEA_HOME}/plugins/gradle/lib/native-platform-windows-i386-0.10.jar
# Remove the bundled native Pty4J support libraries and replace with our own
	@${RM} -r ${STAGEDIR}${IDEA_HOME}/lib/libpty
.if ${PTY4J_ARCH} != ""
	${MKDIR} ${STAGEDIR}${IDEA_HOME}/lib/libpty/freebsd/${PTY4J_ARCH}
# See above why we always use freebsd/x86_64/ here
	${INSTALL_LIB} ${WRKSRC}/os/freebsd/x86_64/libpty.so ${STAGEDIR}${IDEA_HOME}/lib/libpty/freebsd/${PTY4J_ARCH}/
	${INSTALL_DATA} ${WRKSRC}/build/pty4j-0.5.jar ${STAGEDIR}${IDEA_HOME}/lib/pty4j-0.5.jar
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/idea ${STAGEDIR}${PREFIX}/bin/idea
	${INSTALL_MAN} ${FILESDIR}/idea.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/idea.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKDIST}/lib && ${JAVA_HOME}/bin/jar xf icons.jar
	${INSTALL_DATA} ${WRKDIST}/lib/icon.png ${STAGEDIR}${IDEA_HOME}/idea.png
# Disable filewatcher warning message on IDEA startup
	${ECHO} "idea.filewatcher.disabled=true" >> ${STAGEDIR}${IDEA_HOME}/bin/idea.properties

.include <bsd.port.mk>
