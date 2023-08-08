PORTNAME=	r7-office
PORTVERSION=	7.2.2
PORTREVISION=	1
CATEGORIES=	editors linux russian
MASTER_SITES=	https://download.r7-office.ru/ubuntu/
DISTNAME=	r7-office
EXTRACT_SUFX=	.deb

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Russian office suite
WWW=		https://r7-office.ru

LICENSE=	commercial
LICENSE_NAME=	commercial
LICENSE_TEXT=	Commercial software with 30 days trial period
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64

USES=		desktop-file-utils linux shebangfix tar:xz

USE_LINUX=	alsalib base cups-libs gtk3 pulseaudio-libs systemd-libs nss \
		xorglibs

SHEBANG_FILES=	opt/r7-office/desktopeditors/converter/.system/check.sh

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}
STRIP=

post-extract:
	cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} data.tar.xz ${EXTRACT_AFTER_ARGS}

post-patch:
	${REINPLACE_CMD} -i '' 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKDIR}/usr/bin/r7-office-*
	${REINPLACE_CMD} -i '' 's|/usr/bin/|${PREFIX}/bin/|' ${WRKDIR}/usr/share/applications/*.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/r7-office-* ${STAGEDIR}${PREFIX}/bin/
	${RLN} ${STAGEDIR}${PREFIX}/bin/r7-office-desktopeditors ${STAGEDIR}${PREFIX}/bin/r7-office
	cd ${WRKDIR}/opt && ${CP} -r r7-office ${STAGEDIR}${PREFIX}/share
	cd ${WRKDIR}/usr/share && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share

	${RLN} ${STAGEDIR}${DATADIR}/desktopeditors/asc-de-256.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/r7-office.png

	${RM} ${STAGEDIR}${PREFIX}/share/flyfm/templates/.source/*
.for f in new.docx new.pptx new.xlsx
	${RLN} ${STAGEDIR}${DATADIR}/desktopeditors/converter/empty/${f} \
		${STAGEDIR}${PREFIX}/share/flyfm/templates/.source/${f}
.endfor
	${MKDIR} ${STAGEDIR}${LINUXBASE}/etc/r7-office

.include <bsd.port.mk>
