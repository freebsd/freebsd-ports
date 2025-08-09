PORTNAME=	plemoljp-hs
PORTVERSION=	3.0.0
PORTREVISION=	0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/yuru7/PlemolJP/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	PlemolJP_HS_v${DISTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Plex Mono Language JP (Hidden Space)
WWW=		https://github.com/yuru7/PlemolJP

LICENSE=	OFL11

USES=		fonts:fc zip
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_MULTI=			FONT_FAMILY
OPTIONS_MULTI_FONT_FAMILY=	PLEMOLJP_HS PLEMOLJP_CONS_HS PLEMOLJP35_HS \
				PLEMOLJP35_CONS_HS
OPTIONS_DEFAULT=		PLEMOLJP_HS PLEMOLJP_CONS_HS PLEMOLJP35_HS \
				PLEMOLJP35_CONS_HS
PLEMOLJP_HS_DESC=		PlemolJP HS
PLEMOLJP_CONS_HS_DESC=		PlemolJP Console HS
PLEMOLJP35_HS_DESC=		PlemolJP35 HS
PLEMOLJP35_CONS_HS_DESC=	PlemolJP35 Console HS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLEMOLJP_HS}
FONT_FAMILY+=	PlemolJP_HS
.endif
.if ${PORT_OPTIONS:MPLEMOLJP_CONS_HS}
FONT_FAMILY+=	PlemolJPConsole_HS
.endif
.if ${PORT_OPTIONS:MPLEMOLJP35_HS}
FONT_FAMILY+=	PlemolJP35_HS
.endif
.if ${PORT_OPTIONS:MPLEMOLJP35_CONS_HS}
FONT_FAMILY+=	PlemolJP35Console_HS
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
