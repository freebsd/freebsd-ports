PORTNAME=	hackgen-nf
PORTVERSION=	2.9.0
PORTREVISION=	0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/yuru7/HackGen/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	HackGen_NF_v${DISTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	HackGen_NF is a composite font of Hack and GenJyuu-Gothic
WWW=		https://github.com/yuru7/HackGen

LICENSE=	OFL11

USES=		fonts:fc zip
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_MULTI=			FONT_FAMILY
OPTIONS_MULTI_FONT_FAMILY=	HACKGEN_NF HACKGEN35_NF
OPTIONS_DEFAULT=		HACKGEN_NF HACKGEN35_NF
OPTIONS_SUB=			yes
HACKGEN_NF_DESC=		HackGenConsoleNF
HACKGEN35_NF_DESC=		HackGen35ConsoleNF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHACKGEN_NF}
HACKGEN_FONTS+=	HackGenConsoleNF-Regular HackGenConsoleNF-Bold
.endif
.if ${PORT_OPTIONS:MHACKGEN35_NF}
HACKGEN_FONTS+=	HackGen35ConsoleNF-Regular HackGen35ConsoleNF-Bold
.endif

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for FONT in ${HACKGEN_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${FONT}.ttf ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
