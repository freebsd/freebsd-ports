# Created by: masaki
# $FreeBSD$

PORTNAME=	ricty
PORTVERSION=	3.2.1b
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
PKGNAMEPREFIX=	ja-font-

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Ricty - fonts for programming

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
BUILD_DEPENDS=	${LOCALBASE}/${X_FONTSDIR}/OTF/Inconsolata.otf:${PORTSDIR}/x11-fonts/inconsolata-ttf \
		${LOCALBASE}/${X_FONTSDIR}/TTF/migu-1m-regular.ttf:${PORTSDIR}/japanese/font-migu \
		${LOCALBASE}/${X_FONTSDIR}/TTF/migu-1m-bold.ttf:${PORTSDIR}/japanese/font-migu \
		fontforge:${PORTSDIR}/print/fontforge

USE_GITHUB=	yes
GH_ACCOUNT=	yascentur
GH_COMMIT=	${GH_TAGNAME}
GH_PROJECT=	Ricty
GH_TAGNAME=	dfd3637

NO_PACKAGE=	redistribution is not allowed
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
PORTDOCS=	README.md

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

OPTIONS_DEFINE=	DISCORD DOCS
DISCORD_DESC=	Install Ricty-Discord

OPTIONS_DEFAULT=	DISCORD

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDISCORD}
PLIST_SUB+=	DISCORD=""
SUB_LIST+=	DISCORD=""
.else
PLIST_SUB+=	DISCORD="@comment "
SUB_LIST+=	DISCORD="#"
.endif

do-build:
	cd ${WRKSRC} &&\
		${SH} ${WRKSRC}/ricty_generator.sh \
			${PREFIX}/${X_FONTSDIR}/OTF/Inconsolata.otf \
			${PREFIX}/${X_FONTSDIR}/TTF/migu-1m-regular.ttf \
			${PREFIX}/${X_FONTSDIR}/TTF/migu-1m-bold.ttf

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Ricty-*.ttf ${DATADIR}
.if ${PORT_OPTIONS:MDISCORD}
	${INSTALL_DATA} ${WRKSRC}/RictyDiscord-*.ttf ${DATADIR}
.endif
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/TTF
	${LN} -s -f \
		${DATADIR}/*.ttf \
		${PREFIX}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${PREFIX}/${X_FONTSDIR}/TTF
	${LN} -s -f \
		${DATADIR}/*.ttf \
		${PREFIX}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-ricty.conf \
		${FILESDIR}/62-fonts-ricty.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-ricty.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-ricty.conf
	${LN} -s -f ../conf.avail/62-fonts-ricty.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-ricty.conf
.if ${PORT_OPTIONS:MDISCORD}
	${INSTALL_DATA} ${FILESDIR}/20-unhint-rictydiscord.conf \
		${FILESDIR}/62-fonts-rictydiscord.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-rictydiscord.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-rictydiscord.conf
	${LN} -s -f ../conf.avail/62-fonts-rictydiscord.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-rictydiscord.conf
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -f -v ${PREFIX}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
