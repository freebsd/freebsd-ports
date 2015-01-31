# Created by: masaki
# $FreeBSD$

PORTNAME=	ricty
PORTVERSION=	3.2.3
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
PKGNAMEPREFIX=	ja-font-

MAINTAINER?=	meta+ports@vmeta.jp
COMMENT?=	Ricty - fonts for programming

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
BUILD_DEPENDS=	${LOCALBASE}/${X_FONTSDIR}/OTF/Inconsolata.otf:${PORTSDIR}/x11-fonts/inconsolata-ttf \
		${LOCALBASE}/${X_FONTSDIR}/TTF/migu-1m-regular.ttf:${PORTSDIR}/japanese/font-migu \
		${LOCALBASE}/${X_FONTSDIR}/TTF/migu-1m-bold.ttf:${PORTSDIR}/japanese/font-migu \
		fontforge:${PORTSDIR}/print/fontforge

USE_GITHUB=	yes
GH_ACCOUNT=	yascentur
GH_COMMIT=	${GH_TAGNAME}
GH_PROJECT=	Ricty
GH_TAGNAME=	0fd7047

NO_PACKAGE=	redistribution is not allowed
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

.if !defined(PKGNAMESUFFIX)
OPTIONS_DEFINE=	DISCORD DOCS
DISCORD_DESC=	Install Ricty-Discord
OPTIONS_DEFAULT=	DISCORD
PORTDOCS=	README.md
.endif

.include <bsd.port.options.mk>

.if !defined(PKGNAMESUFFIX)
PLIST_SUB+=	DISCORD="@comment " RICTY=""
SUB_LIST+=	DISCORD=\# RICTY=""
.else
PLIST_SUB+=	DISCORD="" RICTY="@comment "
SUB_LIST+=	DISCORD="" RICTY=\#
.endif

.if ${PORT_OPTIONS:MDISCORD}
RUN_DEPENDS+=	${DATADIR}/RictyDiscord-Regular.ttf:${PORTSDIR}/japanese/font-ricty-discord
.endif

do-build:
	cd ${WRKSRC} &&\
		${SH} ${WRKSRC}/ricty_generator.sh \
			${PREFIX}/${X_FONTSDIR}/OTF/Inconsolata.otf \
			${PREFIX}/${X_FONTSDIR}/TTF/migu-1m-regular.ttf \
			${PREFIX}/${X_FONTSDIR}/TTF/migu-1m-bold.ttf

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${X_FONTSDIR}/TTF
	${MKDIR} ${STAGEDIR}${PREFIX}/${LOCAL_FONTSDIR}/TTF
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
.if !defined(PKGNAMESUFFIX)
	${INSTALL_DATA} ${WRKSRC}/Ricty-*.ttf ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${PREFIX}/${LOCAL_FONTSDIR}/TTF && ${LN} -s -f \
	    ../${LOCAL_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/Ricty-*.ttf .
	cd ${STAGEDIR}${PREFIX}/${X_FONTSDIR}/TTF && ${LN} -s -f \
	    ../${X_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/Ricty-*.ttf .
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}.conf \
	    ${FILESDIR}/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}.conf
.else
	${INSTALL_DATA} ${WRKSRC}/RictyDiscord-*.ttf ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${PREFIX}/${LOCAL_FONTSDIR}/TTF && ${LN} -s -f \
	    ../${LOCAL_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/RictyDiscord-*.ttf .
	cd ${STAGEDIR}${PREFIX}/${X_FONTSDIR}/TTF && ${LN} -s -f \
	    ../${X_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/RictyDiscord-*.ttf .
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}discord.conf \
	    ${FILESDIR}/62-fonts-${PORTNAME}discord.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}discord.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}discord.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}discord.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}discord.conf
.endif
.if ${PORT_OPTIONS:MDOCS} && defined(PORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -f -v ${PREFIX}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${STAGEDIR}${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
