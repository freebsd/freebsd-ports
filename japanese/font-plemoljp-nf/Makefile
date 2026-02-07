PORTNAME=	plemoljp-nf
PORTVERSION=	3.0.0
PORTREVISION=	0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/yuru7/PlemolJP/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	PlemolJP_NF_v${DISTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Plex Mono Language JP (Nerd Fonts)
WWW=		https://github.com/yuru7/PlemolJP

LICENSE=	OFL11

USES=		fonts:fc zip
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_MULTI=			FONT_FAMILY
OPTIONS_MULTI_FONT_FAMILY=	PLEMOLJP_CONS_NF PLEMOLJP35_CONS_NF
OPTIONS_DEFAULT=		PLEMOLJP_CONS_NF PLEMOLJP35_CONS_NF
PLEMOLJP_CONS_NF_DESC=		PlemolJP Console NF
PLEMOLJP35_CONS_NF_DESC=	PlemolJP35 Console NF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLEMOLJP_CONS_NF}
FONT_FAMILY+=	PlemolJPConsole_NF
.endif
.if ${PORT_OPTIONS:MPLEMOLJP35_CONS_NF}
FONT_FAMILY+=	PlemolJP35Console_NF
.endif

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for FAMILY in ${FONT_FAMILY}
.  for STYLE in Bold BoldItalic ExtraLight ExtraLightItalic Italic \
		Light LightItalic Medium MediumItalic Regular \
		SemiBold SemiBoldItalic Text TextItalic Thin ThinItalic
	${INSTALL_DATA} ${WRKSRC}/${FAMILY}/${FAMILY:S/_//}-${STYLE}.ttf \
		${STAGEDIR}${FONTSDIR}
	@${ECHO_CMD} ${FONTSDIR}/${FAMILY:S/_//}-${STYLE}.ttf >> ${TMPPLIST}
.  endfor
.endfor

.include <bsd.port.mk>
