PORTNAME=	ganttproject
DISTVERSION=	3.2.3240
CATEGORIES=	deskutils java
MASTER_SITES=	https://github.com/bardsoftware/ganttproject/releases/download/ganttproject-${DISTVERSION}/ \
		https://dl.ganttproject.biz/ganttproject-3.2.3240/

MAINTAINER=	freebsd@ny-central.org
COMMENT=	Gantt chart based project scheduling and management tool
WWW=		https://www.ganttproject.biz/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	openjfx14>=14:java/openjfx14

USES=		desktop-file-utils shebangfix zip
USE_JAVA=	yes
JAVA_VERSION=	11+
SHEBANG_FILES=	ganttproject
bash_CMD=	/bin/sh

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-extract:
	${RM} ${WRKSRC}/ganttproject.exe
	${RM} ${WRKSRC}/ganttproject.bat
	${RM} ${WRKSRC}/ganttproject.command

post-patch:
	${REINPLACE_CMD} -e 's@$$PREFIX@${PREFIX}@g' ${WRKSRC}/ganttproject

do-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${RLN} ${STAGEDIR}${DATADIR}/ganttproject ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	${RLN} ${STAGEDIR}${DATADIR}/plugins/base/ganttproject/resources/icons/ganttproject.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/ganttproject.png
	${INSTALL_DATA} ${FILESDIR}/ganttproject.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
