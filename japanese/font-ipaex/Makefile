PORTNAME=	ipaex
PORTVERSION=	00401
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://ipafont.ipa.go.jp/IPAexfont/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	IPAexfont${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPAex Japanese fonts

LICENSE=	IPAFONTLICv1.0
LICENSE_NAME=	IPA Font License Agreement v1.0
LICENSE_FILE=	${WRKSRC}/IPA_Font_License_Agreement_v1.0.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts:fc zip
FONTPATHSPEC=	${FONTNAME}:pri=60
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
PLIST_SUB=	FONTSDIR=${FONTSDIR}
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PORTDOCS=	Readme_IPAexfont${PORTVERSION}.txt

OPTIONS_DEFINE=	DOCS

post-extract:
	cd ${WRKSRC} && for F in *.ttf; do ${MV} $${F} $${F%.ttf}.otf; done

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${FONTNAME}.conf \
	    ${FILESDIR}/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${FONTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${FONTNAME}.conf

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
