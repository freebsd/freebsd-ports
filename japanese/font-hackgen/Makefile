# $FreeBSD$

PORTNAME=	hackgen
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/yuru7/HackGen/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	HackGen_v${DISTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	HackGen is a composite font of Hack and GenJyuu-Gothic

LICENSE=	OFL11

USES=		fonts:fc zip
FONTPATHSPEC=	${FONTNAME}:pri=60
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_MULTI=			FONT_FAMILY
OPTIONS_MULTI_FONT_FAMILY=	HACKGEN HACKGEN_CONS HACKGEN_CONS_PL \
				HACKGEN35 HACKGEN35_CONS HACKGEN35_CONS_PL
OPTIONS_DEFAULT=		HACKGEN HACKGEN_CONS HACKGEN_CONS_PL \
				HACKGEN35 HACKGEN35_CONS HACKGEN35_CONS_PL
OPTIONS_SUB=			yes
HACKGEN_DESC=			HackGen
HACKGEN_CONS_DESC=		HackGen Console
HACKGEN_CONS_PL_DESC=		HackGen Console for Powerline
HACKGEN35_DESC=			HackGen35
HACKGEN35_CONS_DESC=		HackGen35 Console
HACKGEN35_CONS_PL_DESC=		HackGen35 Console for Powerline

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHACKGEN}
HACKGEN_FONTS+=	HackGen-Regular HackGen-Bold
.endif
.if ${PORT_OPTIONS:MHACKGEN_CONS}
HACKGEN_FONTS+=	HackGenConsole-Regular HackGenConsole-Bold
.endif
.if ${PORT_OPTIONS:MHACKGEN_CONS_PL}
HACKGEN_FONTS+=	HackGenConsole-Regular-forPowerline \
		HackGenConsole-Bold-forPowerline
.endif
.if ${PORT_OPTIONS:MHACKGEN35}
HACKGEN_FONTS+=	HackGen35-Regular HackGen35-Bold
.endif
.if ${PORT_OPTIONS:MHACKGEN35_CONS}
HACKGEN_FONTS+=	HackGen35Console-Regular HackGen35Console-Bold
.endif
.if ${PORT_OPTIONS:MHACKGEN35_CONS_PL}
HACKGEN_FONTS+=	HackGen35Console-Regular-forPowerline \
		HackGen35Console-Bold-forPowerline
.endif

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for FONT in ${HACKGEN_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${FONT}.ttf ${STAGEDIR}${FONTSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${FONTNAME}.conf \
	    ${FILESDIR}/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${FONTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${FONTNAME}.conf

.include <bsd.port.mk>
