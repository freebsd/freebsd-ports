# $FreeBSD$

PORTNAME=	hackgen-nerd
PORTVERSION=	2.2.3
#PORTREVISION=	0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/yuru7/HackGen/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	HackGenNerd_v${DISTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	HackGenNerd is a composite font of Hack and GenJyuu-Gothic

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
OPTIONS_MULTI_FONT_FAMILY=	HACKGENERD HACKGENERD_CONS HACKGEN35NERD HACKGEN35NERD_CONS
OPTIONS_DEFAULT=		HACKGENERD HACKGENERD_CONS HACKGEN35NERD HACKGEN35NERD_CONS
OPTIONS_SUB=			yes
HACKGENERD_DESC=			HackGenNerd
HACKGENERD_CONS_DESC=		HackGenNerd Console
HACKGEN35NERD_DESC=			HackGen35Nerd
HACKGEN35NERD_CONS_DESC=		HackGen35Nerd Console

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHACKGENERD}
HACKGEN_FONTS+=	HackGenNerd-Regular HackGenNerd-Bold
.endif
.if ${PORT_OPTIONS:MHACKGENERD_CONS}
HACKGEN_FONTS+=	HackGenNerdConsole-Regular HackGenNerdConsole-Bold
.endif
.if ${PORT_OPTIONS:MHACKGEN35NERD}
HACKGEN_FONTS+=	HackGen35Nerd-Regular HackGen35Nerd-Bold
.endif
.if ${PORT_OPTIONS:MHACKGEN35NERD_CONS}
HACKGEN_FONTS+=	HackGen35NerdConsole-Regular HackGen35NerdConsole-Bold
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
