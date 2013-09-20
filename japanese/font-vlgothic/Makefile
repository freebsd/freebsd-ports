# Created by: NIIMI Satoshi <sa2c@sa2c.net>
# $FreeBSD$

PORTNAME=	vlgothic
PORTVERSION=	20130607
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SFJP/vlgothic/58961
PKGNAMEPREFIX=	ja-font-
DISTNAME=	VLGothic-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	VLGothic Japanese TrueType fonts

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_XZ=		yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PORTDOCS=	Changelog LICENSE LICENSE.en LICENSE_E.mplus LICENSE_J.mplus \
		README README.sazanami README_J.mplus
WRKSRC=		${WRKDIR}/VLGothic

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/*.ttf \
		${PREFIX}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${PREFIX}/${X_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/*.ttf \
		${PREFIX}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}.conf \
		${FILESDIR}/62-fonts-${PORTNAME}.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}.conf
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -s -f -v ${PREFIX}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
