# Created by: KANOU Hiroki <kanou@mil.allnet.ne.jp>
# $FreeBSD$

PORTNAME=	kochi
PORTVERSION=	20030809
PORTREVISION=	6
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	OSDN/efont/5411/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	${PORTNAME}-substitute-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Kochi Japanese TrueType font

LICENSE=	COPYINGATTACHED
LICENSE_NAME=	Free redistribution with copyright document attached
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=  dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts:fc tar:bzip2
FONTPATHSPEC=	${FONTNAME}:pri=60
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
PLIST_SUB=	FONTSDIR="${FONTSDIR}"
PORTDOCS=	README.ja docs

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
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
	cd ${WRKSRC} && ${CP} -R ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
