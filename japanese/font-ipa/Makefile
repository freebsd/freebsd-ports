# New ports collection makefile for:	font-ipa
# Date created:		26 April 2009
# Whom:			hrs
# $FreeBSD$
#

PORTNAME=	font-ipa
PORTVERSION=	00301
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://info.openlab.ipa.go.jp/ipafont/fontdata/
DISTNAME=	IPAfont${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPA Japanese fonts

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_ZIP=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
PORTDOCS=	IPA_Font_License_Agreement_v1.0.txt \
		Readme${PORTVERSION}.txt

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/OTF
	${LN} -s -f \
		${DATADIR}/ipa*.otf \
		${LOCALBASE}/${LOCAL_FONTSDIR}/OTF/
	${MKDIR} ${LOCALBASE}/${X_FONTSDIR}/OTF
	${LN} -s -f \
		${DATADIR}/ipa*.otf \
		${LOCALBASE}/${X_FONTSDIR}/OTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-ipa.conf \
		${FILESDIR}/62-fonts-ipa.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-ipa.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-ipa.conf
	${LN} -s -f ../conf.avail/62-fonts-ipa.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-ipa.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -f -v ${LOCALBASE}/${X_FONTSDIR}/OTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
