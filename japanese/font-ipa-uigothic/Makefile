# New ports collection makefile for:	font-ipa-uigothic
# Date created:		2 June 2009
# Whom:			hrs
# $FreeBSD$
#

PORTNAME=	font-ipa-uigothic
PORTVERSION=	00203
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://info.openlab.ipa.go.jp/ipafont/fontdata/old/
DISTNAME=	IPAfont${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPA Japanese fonts, UIGothic

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

# ja-font-mplus-ipa-1.0.20060520.p1 has an old ipagui.ttf
CONFLICTS=	ja-font-mplus-ipa-1.0.20060520.p1

USE_ZIP=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
PORTDOCS=	enduser_license.txt \
		Readme${PORTVERSION}.txt

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ipagui.ttf ${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/TTF
	${LN} -s -f \
		${DATADIR}/ipagui.ttf \
		${LOCALBASE}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${LOCALBASE}/${X_FONTSDIR}/TTF
	${LN} -s -f \
		${DATADIR}/ipagui.ttf \
		${LOCALBASE}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-ipa-uigothic.conf \
		${FILESDIR}/62-fonts-ipa-uigothic.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-ipa-uigothic.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-ipa-uigothic.conf
	${LN} -s -f ../conf.avail/62-fonts-ipa-uigothic.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-ipa-uigothic.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -f -v ${LOCALBASE}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
