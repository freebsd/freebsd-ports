PORTNAME=	firge
PORTVERSION=	0.2.0
PORTREVISION=	0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/yuru7/Firge/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	Firge_v${DISTVERSION}

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
OPTIONS_MULTI_FONT_FAMILY=	FIRGE FIRGE_CONS FIRGE35 FIRGE35_CONS
OPTIONS_DEFAULT=		FIRGE FIRGE_CONS FIRGE35 FIRGE35_CONS
OPTIONS_SUB=			yes
FIRGE_DESC=			Firge
FIRGE_CONS_DESC=		Firge Console
FIRGE35_DESC=			Firge35
FIRGE35_CONS_DESC=		Firge35 Console

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFIRGE}
FIRGE_FONTS+=	Firge-Regular Firge-Bold
.endif
.if ${PORT_OPTIONS:MFIRGE_CONS}
FIRGE_FONTS+=	FirgeConsole-Regular FirgeConsole-Bold
.endif
.if ${PORT_OPTIONS:MFIRGE35}
FIRGE_FONTS+=	Firge35-Regular Firge35-Bold
.endif
.if ${PORT_OPTIONS:MFIRGE35_CONS}
FIRGE_FONTS+=	Firge35Console-Regular Firge35Console-Bold
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
