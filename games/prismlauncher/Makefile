PORTNAME=	prismlauncher
DISTVERSION=	11.0.1
CATEGORIES=	games java
MASTER_SITES=	https://github.com/PrismLauncher/PrismLauncher/releases/download/${DISTVERSION}/
DISTNAME=	PrismLauncher-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Minecraft launcher with ability to manage multiple instances
WWW=		https://prismlauncher.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.md

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libcmark.so:textproc/cmark \
		libqrencode.so:graphics/libqrencode \
		libquazip1-qt6.so:archivers/quazip@qt6 \
		libtomlplusplus.so:devel/tomlplusplus
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		lwjgl3>0:games/lwjgl3 \
		xrandr:x11/xrandr

USES=		cmake compiler:c++17-lang desktop-file-utils gl java kde:6 \
		pkgconfig qt:6 shared-mime-info
USE_GITHUB=	nodefault
USE_GL=		opengl
USE_KDE=	ecm:build
USE_QT=		base networkauth

CMAKE_ARGS=	-DJAVA_HOME=${JAVA_HOME} -DJava_JAVAC_EXECUTABLE=${JAVAC} \
		-DLauncher_BUILD_PLATFORM=FreeBSD

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION} >= 20
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-libraries_javacheck_CMakeLists.txt \
		${PATCHDIR}/extra-patch-libraries_launcher_CMakeLists.txt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/launcher/minecraft/LaunchProfile.cpp \
		${WRKSRC}/launcher/minecraft/MinecraftInstance.cpp

.include <bsd.port.post.mk>
