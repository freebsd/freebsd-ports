# $FreeBSD$

PORTNAME=	migmix
PORTVERSION=	1.0.20121030
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	mix-mplus-ipa/57239
PKGNAMEPREFIX=	ja-font-
DISTFILES=	migmix-1m-20121030${EXTRACT_SUFX} \
		migmix-2m-20121030${EXTRACT_SUFX} \
		migmix-1p-20121030${EXTRACT_SUFX} \
		migmix-2p-20121030${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Mixed Japanese font with IPA Gothic and M-plus outline

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_ZIP=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
PORTDOCS=	IPA_Font_License_Agreement_v1.0.txt Readme_ipag00303.txt \
		migmix-README.txt
LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

do-install:
	cd ${WRKDIR}/migmix-1m-20121030/ && \
		${INSTALL_DATA} ipag00303/*.txt \
			migmix-README.txt \
			${WRKDIR}
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} \
		${WRKDIR}/migmix-1m-20121030/*.ttf \
		${WRKDIR}/migmix-2m-20121030/*.ttf \
		${WRKDIR}/migmix-1p-20121030/*.ttf \
		${WRKDIR}/migmix-2p-20121030/*.ttf \
		${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/migmix*.ttf \
		${PREFIX}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${PREFIX}/${X_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/migmix*.ttf \
		${PREFIX}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-migmix.conf \
		${FILESDIR}/62-fonts-migmix.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-migmix.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-migmix.conf
	${LN} -s -f ../conf.avail/62-fonts-migmix.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-migmix.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -s -f -v ${PREFIX}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
