PORTNAME=	plemoljp
PORTVERSION=	3.0.0
PORTREVISION=	0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/yuru7/PlemolJP/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	PlemolJP_v${DISTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Plex Mono Language JP
WWW=		https://github.com/yuru7/PlemolJP

LICENSE=	OFL11

USES=		fonts:fc zip
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_MULTI=			FONT_FAMILY
OPTIONS_MULTI_FONT_FAMILY=	PLEMOLJP PLEMOLJP_CONS PLEMOLJP35 PLEMOLJP35_CONS
OPTIONS_DEFAULT=		PLEMOLJP PLEMOLJP_CONS PLEMOLJP35 PLEMOLJP35_CONS
PLEMOLJP_DESC=			PlemolJP
PLEMOLJP_CONS_DESC=		PlemolJP Console
PLEMOLJP35_DESC=		PlemolJP35
PLEMOLJP35_CONS_DESC=		PlemolJP35 Console

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLEMOLJP}
FONT_FAMILY+=	PlemolJP
.endif
.if ${PORT_OPTIONS:MPLEMOLJP_CONS}
FONT_FAMILY+=	PlemolJPConsole
.endif
.if ${PORT_OPTIONS:MPLEMOLJP35}
FONT_FAMILY+=	PlemolJP35
.endif
.if ${PORT_OPTIONS:MPLEMOLJP35_CONS}
FONT_FAMILY+=	PlemolJP35Console
.endif

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for FAMILY in ${FONT_FAMILY}
.  for STYLE in Bold BoldItalic ExtraLight ExtraLightItalic Italic \
		Light LightItalic Medium MediumItalic Regular \
		SemiBold SemiBoldItalic Text TextItalic Thin ThinItalic
	${INSTALL_DATA} ${WRKSRC}/${FAMILY}/${FAMILY}-${STYLE}.ttf \
		${STAGEDIR}${FONTSDIR}
	@${ECHO_CMD} ${FONTSDIR}/${FAMILY}-${STYLE}.ttf >> ${TMPPLIST}
.  endfor
.endfor

.include <bsd.port.mk>
