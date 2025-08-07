PORTNAME=	r7-office
PORTVERSION=	2025.2.2
DISTVERSIONSUFFIX=	-831.el8
CATEGORIES=	editors linux russian
MASTER_SITES=	https://download.r7-office.ru/centos/
PKGNAMEPREFIX=	linux-
EXTRACT_SUFX=	.x86_64.rpm

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Russian office suite
WWW=		https://r7-office.ru

LICENSE=	commercial
LICENSE_NAME=	commercial
LICENSE_TEXT=	Commercial software with 30 days trial period
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64

USES=		desktop-file-utils linux:rl9 shared-mime-info shebangfix tar:xz

USE_LINUX=	alsalib base cups-libs curl gstreamer1-libav gtk3 opus \
		pulseaudio-libs nss p11-kit systemd-libs xorglibs

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}
STRIP=

post-patch:
	${REINPLACE_CMD} -i '' -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKDIR}/usr/bin/r7-office-*
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/|${PREFIX}/bin/|' -e 's|P7|Р7|' \
		${WRKDIR}/usr/share/applications/*.desktop
	${REINPLACE_CMD} -i '' -e 's|/bin/bash|/bin/sh|' \
		${WRKDIR}/opt/r7-office/desktopeditors/testbird.sh

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/r7-office-* ${STAGEDIR}${PREFIX}/bin/
	${RLN} ${STAGEDIR}${PREFIX}/bin/r7-office-desktopeditors ${STAGEDIR}${PREFIX}/bin/r7-office
	cd ${WRKDIR}/opt && ${CP} -r r7-office ${STAGEDIR}${PREFIX}/share
	cd ${WRKDIR}/usr/share && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share
	${RLN} ${STAGEDIR}${DATADIR}/desktopeditors/asc-de-256.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/r7-office.png

	${RM} ${STAGEDIR}${PREFIX}/bin/*.orig
	${RM} ${STAGEDIR}${PREFIX}/share/flyfm/templates/.source/*
	${MKDIR} ${STAGEDIR}${PREFIX}/share/flyfm/templates/.source
.for f in new.docx new.pptx new.xlsx
	${RLN} ${STAGEDIR}${DATADIR}/desktopeditors/converter/empty/${f} \
		${STAGEDIR}${PREFIX}/share/flyfm/templates/.source/${f}
.endfor
	${MKDIR} ${STAGEDIR}${LINUXBASE}/etc/r7-office

.include <bsd.port.mk>
