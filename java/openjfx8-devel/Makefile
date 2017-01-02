# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	openjfx8
PORTVERSION=	20160228
PORTREVISION=	1
CATEGORIES=	java x11-toolkits devel
MASTER_SITES=	https://bitbucket.org/tobik/openjfx-rt/get/ \
		http://bitbucket.org/tobik/openjfx-rt/get/
PKGNAMESUFFIX=	-devel
DISTNAME=	freebsd${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	t@tobik.me
COMMENT=	JavaFX (OpenJFX) SDK overlay for OpenJDK 8

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	apache-ant>0:devel/apache-ant \
		antlr3>0:devel/antlr3 \
		gradle:devel/gradle \
		swt-devel>0:x11-toolkits/swt-devel
RUN_DEPENDS=	swt-devel>0:x11-toolkits/swt-devel

USES=		jpeg
USE_GL=		yes
USE_GNOME=	gtk20
USE_JAVA=	yes
USE_LDCONFIG=	yes
JAVA_VERSION=	1.8

ONLY_FOR_ARCHS=	i386 amd64
PLIST_SUB=	ARCH=${ARCH} \
		JAVA_HOME=${JAVA_HOME}

WRKSRC=	${WRKDIR}/tobik-openjfx-rt-2de985ca8377

# NOTE: This port won't build if openjfx8-devel is currently
# installed.  This is not a problem in Poudriere or Synth but
# something to be aware of if you're trying to build this port in a
# non-pristine environment.

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/build.gradle ${WRKSRC}/buildSrc/build.gradle

do-build:
# Gradle creates ${HOME}/.gradle, pretend home is somewhere else
	@${MKDIR} ${WRKDIR}/dot-gradle
	@(cd ${WRKSRC}; ${SETENV} GRADLE_USER_HOME=${WRKDIR}/dot-gradle gradle zips)

do-install:
	@(${MKDIR} ${STAGEDIR}${JAVA_HOME} \
		&& ${TAR} -C ${STAGEDIR}${JAVA_HOME} \
			-xf ${WRKSRC}/build/bundles/javafx-sdk-overlay.zip)

	@${FIND} ${STAGEDIR}${JAVA_HOME}/jre -name '*.so' -exec ${STRIP_CMD} \{\} \;

.include <bsd.port.mk>
