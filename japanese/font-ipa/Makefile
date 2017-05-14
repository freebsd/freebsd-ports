# $FreeBSD$

PORTNAME=	ipa
PORTVERSION=	00303
PORTREVISION=	6
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://dl.ipafont.ipa.go.jp/IPAfont/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	IPAfont${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPA Japanese fonts

CONFLICTS=	ja-ipa-ttfonts-[0-9]*

USES=		fonts:fc zip
FONTNAME=	OTF
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PORTDOCS=	IPA_Font_License_Agreement_v1.0.txt \
		Readme_IPAfont${PORTVERSION}.txt

OPTIONS_DEFINE=	DOCS

post-extract:
	cd ${WRKSRC} && for F in *.ttf; do ${MV} $${F} $${F%.ttf}.otf; done

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR}/ && ${LN} -s -f \
	    ../../../${DATADIR_REL}/ipa*.otf .
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}.conf \
	    ${FILESDIR}/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}.conf

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
