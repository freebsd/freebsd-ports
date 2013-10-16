# $FreeBSD$

PORTNAME=	mona-ipa
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.geocities.jp/ipa_mona/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	opfc-ModuleHP-1.1.1_withIPAMonaFonts-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPA Japanese TrueType fonts with Mona font

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PORTDOCS=	COPYING.font.ja README_ipamona.txt

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${LOCAL_FONTSDIR}/TTF/
	cd ${STAGEDIR}${PREFIX}/${LOCAL_FONTSDIR}/TTF/ && ${LN} -s -f \
	    ../${LOCAL_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/fonts/ipa*-mona.ttf .
	${MKDIR} ${STAGEDIR}${PREFIX}/${X_FONTSDIR}/TTF
	cd ${STAGEDIR}${PREFIX}/${X_FONTSDIR}/TTF/ && ${LN} -s -f \
	    ../${X_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/fonts/ipa*-mona.ttf .
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}.conf \
	    ${FILESDIR}/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}.conf

post-su-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/fonts && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
