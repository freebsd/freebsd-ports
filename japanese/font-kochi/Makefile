# Created by: KANOU Hiroki <kanou@mil.allnet.ne.jp>
# $FreeBSD$

PORTNAME=	kochi
PORTVERSION=	20030809
PORTREVISION=	4
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SFJP/efont/5411/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	${PORTNAME}-substitute-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Kochi Japanese TrueType font

USES=		fonts tar:bzip2
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PLIST_SUB=	DATADIR=share/font-${PORTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}

FONTNAME=	TTF
PORTDOCS=	README.ja COPYING docs

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && ${LN} -s -f \
	    ../../../${DATADIR_REL}/*.ttf .
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
	cd ${WRKSRC} && ${CP} -R ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
