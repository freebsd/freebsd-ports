# $FreeBSD$

PORTNAME=	mplus
PORTVERSION=	1.0.20060520.p1
PORTREVISION=	6
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	LOCAL/hrs
PKGNAMEPREFIX=	ja-font-
PKGNAMESUFFIX=	-ipa
DISTNAME=	mixfont-mplus-ipa-TrueType-20060520p1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Mixed Japanese font with IPA, M-plus outline, and Bitstream Vera

LICENSE=	NOTPARTIAL
LICENSE_NAME=	Whole not partial
LICENSE_TEXT=	Free redistribution of the whole package allowed, not partial
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts:fc tar:bzip2
FONTNAME=	${PORTNAME}${PKGNAMESUFFIX}
FONTPATHSPEC=	${FONTNAME}:pri=60
FONTSDIR=	${PREFIX}/share/fonts/${FONTNAME}/fonts
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
PLIST_SUB=	FONTSDIR=${FONTSDIR:S,/fonts$,,}
PORTDOCS=	Bitstream-COPYRIGHT.txt Mplus-LICENSE_E.txt \
		Mplus-LICENSE_J.txt README.txt

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/opfc-ModuleHP-1.1.1_withIPAFonts_and_Mplus && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}/${FONTSDIR}/..
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
