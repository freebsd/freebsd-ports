# New ports collection makefile for:	font-ipaex
# Date created:		2 March 2010
# Whom:			hrs
# $FreeBSD$
#

PORTNAME=	font-ipaex
PORTVERSION=	00103
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://info.openlab.ipa.go.jp/ipafont/fontdata/
DISTNAME=	IPAexfont${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPAex Japanese fonts

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
		Readme_IPAexfont${PORTVERSION}.txt

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

post-extract:
	cd ${WRKSRC} && for F in *.ttf; do ${MV} $${F} $${F%.ttf}.otf; done

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/OTF
	${LN} -s -f \
		${DATADIR}/ipaex*.otf \
		${PREFIX}/${LOCAL_FONTSDIR}/OTF/
	${MKDIR} ${PREFIX}/${X_FONTSDIR}/OTF
	${LN} -s -f \
		${DATADIR}/ipaex*.otf \
		${PREFIX}/${X_FONTSDIR}/OTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-ipaex.conf \
		${FILESDIR}/62-fonts-ipaex.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-ipaex.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-ipaex.conf
	${LN} -s -f ../conf.avail/62-fonts-ipaex.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-ipaex.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -f -v ${PREFIX}/${X_FONTSDIR}/OTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
