PORTNAME=	firge-nerd
PORTVERSION=	0.2.0
PORTREVISION=	0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/yuru7/Firge/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	FirgeNerd_v${DISTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Firge is a composite font of Fira Mono and GenShin-Gothic

LICENSE=	OFL11

USES=		fonts:fc zip
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_MULTI=			FONT_FAMILY
OPTIONS_MULTI_FONT_FAMILY=	FIRGENERD FIRGENERD_CONS FIRGE35NERD FIRGE35NERD_CONS
OPTIONS_DEFAULT=		FIRGENERD FIRGENERD_CONS FIRGE35NERD FIRGE35NERD_CONS
OPTIONS_SUB=			yes
FIRGENERD_DESC=			FirgeNerd
FIRGENERD_CONS_DESC=		FirgeNerd Console
FIRGE35NERD_DESC=		Firge35Nerd
FIRGE35NERD_CONS_DESC=		Firge35Nerd Console

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFIRGENERD}
FIRGE_FONTS+=	FirgeNerd-Regular FirgeNerd-Bold
.endif
.if ${PORT_OPTIONS:MFIRGENERD_CONS}
FIRGE_FONTS+=	FirgeNerdConsole-Regular FirgeNerdConsole-Bold
.endif
.if ${PORT_OPTIONS:MFIRGE35NERD}
FIRGE_FONTS+=	Firge35Nerd-Regular Firge35Nerd-Bold
.endif
.if ${PORT_OPTIONS:MFIRGE35NERD_CONS}
FIRGE_FONTS+=	Firge35NerdConsole-Regular Firge35NerdConsole-Bold
.endif

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for FONT in ${FIRGE_FONTS}
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
