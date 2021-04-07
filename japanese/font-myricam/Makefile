PORTNAME=	myricam
PORTVERSION=	2.012.20180119
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/tomokuni/Myrica/raw/master/product/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	MyricaM
DIST_SUBDIR=	${DISTNAME}-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Myrica free TrueType fonts for programming

USES=		fonts:fc 7z
FONTPATHSPEC=	${FONTNAME}:pri=60
NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
WRKSRC=		${WRKDIR}/${DISTNAME}
PORTDOCS=	LICENSE_M+.txt LICENSE_OFL.txt README.md

# Upstream archive contains files with UTF-8 names
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.TTC ${STAGEDIR}${FONTSDIR}
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
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
