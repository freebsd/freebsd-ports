# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	jd-gui
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	java devel
MASTER_SITES=	GH:src \
		https://github.com/java-decompiler/jd-gui/releases/download/v${PORTVERSION}/:jar
DISTFILES=	${DISTNAME}.tar.gz:src \
		jd-gui-${PORTVERSION}.jar:jar
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	t@tobik.me
COMMENT=	Java Decompiler GUI

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	java-decompiler

USE_JAVA=	yes
JAVA_VERSION=	1.7+
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/jd-gui \
		%%JAVAJARDIR%%/jd-gui.jar \
		share/applications/jd-gui.desktop \
		share/pixmaps/jd-gui.png

SUB_FILES=	jd-gui
SUB_LIST=	JAVAJARDIR="${JAVAJARDIR}"

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jd-gui ${STAGEDIR}${PREFIX}/bin/jd-gui
	${INSTALL_DATA} ${DISTDIR}/jd-gui-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/jd-gui.jar
	${INSTALL_DATA} ${WRKSRC}/src/linux/resources/jd-gui.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/src/linux/resources/jd_icon_128.png ${STAGEDIR}${PREFIX}/share/pixmaps/jd-gui.png

.include <bsd.port.mk>
