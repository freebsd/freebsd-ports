# $FreeBSD$

PORTNAME=	ipa-uigothic
PORTVERSION=	00203
PORTREVISION=	2
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://info.openlab.ipa.go.jp/ipafont/fontdata/old/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	IPAfont${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPA Japanese fonts, UIGothic

# ja-font-mplus-ipa-1.0.20060520.p1 has an old ipagui.ttf
CONFLICTS=	ja-font-mplus-ipa-1.0.20060520.p1 \
		ja-ipa-ttfonts-[0-9]*

USES=		fonts zip
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PORTDOCS=	enduser_license.txt \
		Readme${PORTVERSION}.txt

FONTNAME=	TTF
OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ipagui.ttf ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && ${LN} -s -f \
	    ../../../${DATADIR_REL}/ipagui.ttf .
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}.conf \
	    ${FILESDIR}/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}.conf
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
