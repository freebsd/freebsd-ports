# New ports collection makefile for:	font-mplus-ipa fonts
# Date created:		26 April 2009
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	font-mplus-ipa
PORTVERSION=	1.0.20060520.p1
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hrs
DISTNAME=	mixfont-mplus-ipa-TrueType-20060520p1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Mixed Japanese font with IPA, M-plus outline, and Bitstream Vera

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

CONFLICTS=	ja-ipa-ttfonts-[0-9]*

USE_BZIP2=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
PORTDOCS=	Bitstream-COPYRIGHT.txt Mplus-LICENSE_E.txt \
		Mplus-LICENSE_J.txt README.txt

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

do-install:
	${MKDIR} ${DATADIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}
	${CP} -R ${WRKSRC}/opfc-ModuleHP-1.1.1_withIPAFonts_and_Mplus/* \
		${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/fonts/M+*.ttf \
		${LOCALBASE}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${LOCALBASE}/${X_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/fonts/M+*.ttf \
			${LOCALBASE}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-mplus-ipa.conf \
		${FILESDIR}/62-fonts-mplus-ipa.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-mplus-ipa.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-mplus-ipa.conf
	${LN} -s -f ../conf.avail/62-fonts-mplus-ipa.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-mplus-ipa.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -s -f -v ${LOCALBASE}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
