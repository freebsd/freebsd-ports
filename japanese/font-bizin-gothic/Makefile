PORTNAME=	bizin-gothic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.4
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/yuru7/bizin-gothic/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	BizinGothic_${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	Font for programming composed of BizUD gothic and Inconsolata
WWW=		https://github.com/yuru7/bizin-gothic

LICENSE=	OFL11

USES=		fonts:fc zip

FONT_PATHSPEC=	${FONTNAME}:pri=60
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/BizinGothic-Regular.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/BizinGothic-Bold.ttf ${STAGEDIR}${FONTSDIR}
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
