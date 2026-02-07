PORTNAME=	moralerspace-jpdoc
PORTVERSION=	2.0.0
PORTREVISION=	0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/yuru7/${FONTNAME}/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	${FONTNAME}${VARIATION}_v${DISTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Moralerspace Font (Regular version for JP Doc)
WWW=		https://github.com/yuru7/moralerspace

LICENSE=	OFL11

USES=		fonts:fc zip
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_MULTI=			FONT_FAMILY
OPTIONS_MULTI_FONT_FAMILY=	ARGON KRYPTON NEON RADON XENON
OPTIONS_DEFAULT=		ARGON KRYPTON NEON RADON XENON
ARGON_DESC=			Argon (Humanist sans)
KRYPTON_DESC=			Krypton (Mechanical sans)
NEON_DESC=			Neon (neo-grotesque sans)
RADON_DESC=			Radon (Handwriting)
XENON_DESC=			Xenon (Slab serif)

FONTNAME=	Moralerspace
VARIATION=	JPDOC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MARGON}
FONT_FAMILY+=	Argon
.endif
.if ${PORT_OPTIONS:MKRYPTON}
FONT_FAMILY+=	Krypton
.endif
.if ${PORT_OPTIONS:MNEON}
FONT_FAMILY+=	Neon
.endif
.if ${PORT_OPTIONS:MRADON}
FONT_FAMILY+=	Radon
.endif
.if ${PORT_OPTIONS:MXENON}
FONT_FAMILY+=	Xenon
.endif

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for FAMILY in ${FONT_FAMILY}
.  for STYLE in Bold BoldItalic Italic Regular
	${INSTALL_DATA} ${WRKSRC}/${FONTNAME}${FAMILY}${VARIATION}-${STYLE}.ttf ${STAGEDIR}${FONTSDIR}
	@${ECHO_CMD} ${FONTSDIR}/${FONTNAME}${FAMILY}${VARIATION}-${STYLE}.ttf >> ${TMPPLIST}
.  endfor
.endfor

.include <bsd.port.mk>
