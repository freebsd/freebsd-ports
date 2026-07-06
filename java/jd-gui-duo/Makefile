PORTNAME=	jd-gui-duo
DISTVERSION=	2.0.113
CATEGORIES=	java devel
MASTER_SITES=	https://github.com/nbauma109/${PORTNAME}/releases/download/${DISTVERSION}/ \
		https://raw.githubusercontent.com/nbauma109/${PORTNAME}/refs/tags/${DISTVERSION}/src/launch4j/resources/images/:ico
DISTNAME=	${PORTNAME}-linux-${DISTVERSION}
DISTFILES=	${EXTRACT_ONLY} \
		jd-gui.ico:ico
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Java Decompiler GUI
WWW=		https://github.com/nbauma109/jd-gui-duo/

LICENSE=	GPLv3

USES=		desktop-file-utils java tar:xz
JAVA_VERSION=	25+

EXTRACT_AFTER_ARGS=	--exclude jre \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	${PORTNAME}.desktop
SUB_LIST=	JAVA=${JAVA}
NO_WRKSUBDIR=	yes

post-patch:
	${REINPLACE_CMD} 's|%%JAVAJARDIR%%|${JAVAJARDIR}|' ${WRKSRC}/jd-gui-duo.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/jd-gui.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico

.include <bsd.port.mk>
