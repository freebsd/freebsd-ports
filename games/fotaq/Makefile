PORTNAME=	fotaq
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/scummvm/extras/Flight%20of%20the%20Amazon%20Queen \
		https://downloads.scummvm.org/frs/extras/Flight%20of%20the%20Amazon%20Queen/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Flight of the Amazon Queen: a classic graphical adventure
WWW=		https://www.scummvm.org/

LICENSE=	FOTAQ
LICENSE_NAME=	Flight of the Amazon Queen license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	scummvm:games/scummvm

USES=		desktop-file-utils zip

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	fotaq.desktop
PLIST_FILES=	share/applications/fotaq.desktop \
		${DATADIR}/queen.1c
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		LANG
OPTIONS_SINGLE_LANG=	LANG_DE LANG_EN LANG_FR LANG_HE LANG_IT
OPTIONS_DEFAULT=	LANG_EN

LANG_DESC=		Languages
LANG_DE_DISTFILES=	FOTAQ_Ger_talkie-1.0${EXTRACT_SUFX}
LANG_EN_DESC=		English language support
LANG_EN_DISTFILES=	FOTAQ_Talkie-${PORTVERSION}${EXTRACT_SUFX}
LANG_FR_DISTFILES=	FOTAQ_Fr_Talkie_1.0${EXTRACT_SUFX}
LANG_HE_DISTFILES=	FOTAQ_Heb_talkie${EXTRACT_SUFX}
LANG_IT_DISTFILES=	FOTAQ_It_Talkie_1.0${EXTRACT_SUFX}

.include <bsd.port.options.mk>

post-extract:
.if ${PORT_OPTIONS:MLANG_DE} || ${PORT_OPTIONS:MLANG_HE}
	@${FMT} ${WRKSRC}/COPYING > ${WRKSRC}/LICENSE
.elif ${PORT_OPTIONS:MLANG_FR} || ${PORT_OPTIONS:MLANG_IT}
	@${TAIL} -n +83 ${WRKSRC}/readme.txt | ${SED} -e '1G;10G' | ${FMT} -p > ${WRKSRC}/LICENSE
.elif ${PORT_OPTIONS:MLANG_EN}
	@${TAIL} -n +81 ${WRKSRC}/readme.txt | ${SED} -e '1G;10G' | ${FMT} -p > ${WRKSRC}/LICENSE
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/queen.1c ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/fotaq.desktop ${STAGEDIR}${PREFIX}/share/applications
.if !${PORT_OPTIONS:MLANG_DE} && !${PORT_OPTIONS:MLANG_HE}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
