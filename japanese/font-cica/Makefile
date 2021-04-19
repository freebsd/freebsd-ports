PORTNAME=	cica
PORTVERSION=	5.0.2
PORTREVISION=	0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/miiton/Cica/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	Cica_v${DISTVERSION}_${OPT_EMOJI}_emoji

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Cica Japanese monospaced fonts for programming

LICENSE=	OFL11

USES=		fonts:fc zip
FONTPATHSPEC=	${FONTNAME}:pri=60
NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
WRKSRC=		${WRKDIR}/${DISTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS EMOJI
OPTIONS_DEFAULT=EMOJI
EMOJI_DESC=	With Emoji

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMOJI}
OPT_EMOJI=	with
.else
OPT_EMOJI=	without
.endif

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${FONTNAME}.conf \
	    ${FILESDIR}/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${FONTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${FONTNAME}.conf

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name *\.ttf"

makesums:
	${MAKE} rmconfig
	${MAKE} makesum OPTIONS_UNSET=EMOJI
	${MV} distinfo .distinfo.without_emoji
	${MAKE} makesum OPTIONS_SET=EMOJI
	tail -2 .distinfo.without_emoji >> distinfo
	${RM} .distinfo.without_emoji

.include <bsd.port.mk>
