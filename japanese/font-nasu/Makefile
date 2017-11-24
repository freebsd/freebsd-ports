# $FreeBSD$

PORTNAME=	nasu
PORTVERSION=	20141215
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SOURCEFORGE_JP/users/7/7587
PKGNAMEPREFIX=	ja-font-
DISTNAME=	NasuFont-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Nasu Japanese TrueType fonts

LICENSE=	APACHE20

USES=		fonts:fc zip
FONTNAME=	nasu
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
WRKSRC=		${WRKDIR}/${DISTNAME:C/-//}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}
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
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! ( -name Nasu-Bold-20141215.ttf \
		-o -name Nasu-Regular-20141215.ttf \
		-o -name NasuM-Bold-20141215.ttf \
		-o -name NasuM-Regular-20141215.ttf )"

.include <bsd.port.mk>
