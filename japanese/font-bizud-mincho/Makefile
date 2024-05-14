PORTNAME=	bizud-mincho
DISTVERSION=	1.06
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/googlefonts/morisawa-biz-ud-mincho/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	morisawa-biz-ud-mincho-fonts
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Morisawa BIZ UD Mincho fonts
WWW=		https://github.com/googlefonts/morisawa-biz-ud-mincho

LICENSE=	OFL11

USES=		fonts:fc

EXTRACT_AFTER_ARGS=	--include morisawa-biz-ud-mincho-fonts/fonts/ttf/*.ttf \
			--strip-components 3 \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTPATHSPEC=	${FONTNAME}:pri=60
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${FONTNAME}.conf \
	    ${FILESDIR}/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${FONTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${FONTNAME}.conf

.include <bsd.port.mk>
