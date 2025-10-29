PORTNAME=	podman-desktop
PORTVERSION=	1.21.0
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/arrowd/podman-desktop/releases/download/v${PORTVERSION}/ \
		https://raw.githubusercontent.com/podman-desktop/podman-desktop/refs/tags/v${PORTVERSION}/buildResources/:icon
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		icon.svg:icon
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Graphical tool for developing on containers and Kubernetes
WWW=		https://podman-desktop.io/

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	bash:shells/bash \
		kubectl:sysutils/kubectl \
		minikube:sysutils/minikube \
		podman-compose:sysutils/podman-compose

USES=		desktop-file-utils electronfix:37 shared-mime-info

ELECTRONFIX_MAIN_EXECUTABLE=	podman-desktop
SUB_FILES=	podman-desktop
NO_BUILD=	yes
DIST_SUBDIR=	${PORTNAME}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/podman-desktop ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${PATCHDIR}/podman-desktop.desktop ${STAGEDIR}${DESKTOPDIR}/podman-desktop.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/icon.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/

.include <bsd.port.mk>
