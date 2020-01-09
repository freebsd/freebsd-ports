# $FreeBSD$

PORTNAME=	ricty
PORTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://rictyfonts.github.io/files/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	ricty_generator-${PORTVERSION}.sh
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	${PORTNAME}

MAINTAINER?=	meta@FreeBSD.org
COMMENT?=	Ricty - fonts for programming

LICENSE=	OFL11 IPAFONTLICv1.0
LICENSE_COMB=	multi
LICENSE_NAME_IPAFONTLICv1.0=	IPA Font License Agreement v1.0
LICENSE_TEXT_IPAFONTLICv1.0=	https://opensource.org/licenses/IPA
# No package redistribution due to OFL11
LICENSE_PERMS_IPAFONTLICv1.0=	dist-mirror dist-sell no-pkg-mirror \
		no-pkg-sell auto-accept

BUILD_DEPENDS=	inconsolata-ttf>=2.000:x11-fonts/inconsolata-ttf \
		${LOCALBASE}/share/fonts/migu/migu-1m-regular.ttf:japanese/font-migu \
		${LOCALBASE}/share/fonts/migu/migu-1m-bold.ttf:japanese/font-migu \
		fontforge:print/fontforge

USES=		fonts:fc
FONTNAME=	${PORTNAME}${PKGNAMESUFFIX}
FONTPATHSPEC=	${FONTNAME}:pri=60

NO_ARCH=	yes
SUB_FILES=	genfontsdir.sh

.if !defined(MASTERDIR)
OPTIONS_DEFINE=	DISCORD
OPTIONS_DEFAULT=DISCORD
DISCORD_DESC=	Install Ricty-Discord
DISCORD_RUN_DEPENDS=	${LOCALBASE}/share/fonts/ricty-discord/RictyDiscord-Regular.ttf:japanese/font-ricty-discord
.endif

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == no
SUB_LIST+=	DISCORD="" RICTY=\#
.else
SUB_LIST+=	DISCORD=\# RICTY=""
.endif

do-extract:
	@${MKDIR} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${SH} ${DISTDIR}/${DIST_SUBDIR}/ricty_generator-${PORTVERSION}.sh \
			${LOCALBASE}/share/fonts/inconsolata/Inconsolata-Regular.ttf \
			${LOCALBASE}/share/fonts/inconsolata/Inconsolata-Bold.ttf \
			${LOCALBASE}/share/fonts/migu/migu-1m-regular.ttf \
			${LOCALBASE}/share/fonts/migu/migu-1m-bold.ttf

pre-install:
	cd ${WRKDIR} && ${SH} ./genfontsdir.sh

do-install:
	@${MKDIR} \
	    ${STAGEDIR}${FONTSDIR} \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
.if ${SLAVE_PORT} == no
	${INSTALL_DATA} ${WRKDIR}/fonts.dir ${WRKSRC}/Ricty-*.ttf \
	    ${STAGEDIR}${FONTSDIR}
.else
	${INSTALL_DATA} ${WRKDIR}/fonts.dir ${WRKSRC}/RictyDiscord-*.ttf \
	    ${STAGEDIR}${FONTSDIR}
.endif
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${FONTNAME}.conf \
	    ${FILESDIR}/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${RLN} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail/20-unhint-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${FONTNAME}.conf
	${RLN} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${FONTNAME}.conf

.include <bsd.port.mk>
