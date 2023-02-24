PORTNAME=	r7-office
PORTVERSION=	7.2.2
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
	${REINPLACE_CMD} 's|/opt/r7-office/|${DATADIR}/|' ${WRKDIR}/usr/bin/r7-office-*
	${RM} ${WRKDIR}/usr/bin/*.bak
	${REINPLACE_CMD} 's|/usr/bin/|${PREFIX}/|' ${WRKDIR}/usr/share/applications/*.desktop
	${RM} ${WRKDIR}/usr/share/applications/*.bak

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/r7-office-* ${STAGEDIR}${PREFIX}/bin/
	${RLN} ${STAGEDIR}${PREFIX}/bin/r7-office-desktopeditors ${STAGEDIR}${PREFIX}/bin/r7-office
	cd ${WRKDIR}/opt && ${CP} -r r7-office ${STAGEDIR}${PREFIX}/share
	cd ${WRKDIR}/usr/share && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share

	${RM} ${STAGEDIR}${PREFIX}/share/flyfm/templates/.source/*
.for f in new.docx new.pptx new.xlsx
	${RLN} ${STAGEDIR}${DATADIR}/desktopeditors/converter/empty/${f} \
		${STAGEDIR}${PREFIX}/share/flyfm/templates/.source/${f}
.endfor
	${MKDIR} ${STAGEDIR}${LINUXBASE}/etc/r7-office

.include <bsd.port.mk>
