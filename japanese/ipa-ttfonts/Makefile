# New ports collection makefile for:	IPA TrueType fonts
# Date created:		18 July 2004
# Whom:			NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipa-ttfonts
PORTVERSION=	1.0.20060520
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	mix-mplus-ipa/20216
DISTNAME=	mixfont-mplus-ipa-TrueType-20060520

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPA Japanese TrueType fonts with M-plus outline font

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/mixfont-mplus-ipa-TrueType-20060520
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install

SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts
DATADIR=	${LOCALBASE}/share/${PORTNAME}

USE_X_PREFIX=	yes

PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		FONTSDIR_EXTRA=${X_FONTSDIR}/fonts.dir.ipa \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR} \
		DATADIR=share/${PORTNAME}

PORTDOCS=	Bitstream-COPYRIGHT.txt Mplus-LICENSE_E.txt \
		Mplus-LICENSE_J.txt README.txt

do-install:
	${MKDIR} ${DATADIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}
	${CP} -R ${WRKSRC}/opfc-ModuleHP-1.1.1_withIPAFonts_and_Mplus/* \
		${DATADIR}
	${MKDIR} ${LOCALBASE}/${LOCAL_FONTSDIR}/TrueType/
	${LN} -s -f \
		${DATADIR}/fonts/ipa*.ttf \
		${LOCALBASE}/${LOCAL_FONTSDIR}/TrueType/
	${LN} -s -f \
		${DATADIR}/fonts/M+*.ttf \
		${LOCALBASE}/${LOCAL_FONTSDIR}/TrueType/
	${MKDIR} ${PREFIX}/${X_FONTSDIR}/TrueType
	${LN} -s -f \
		${DATADIR}/fonts/ipa*.ttf \
		${PREFIX}/${X_FONTSDIR}/TrueType/
	${LN} -s -f \
		${DATADIR}/fonts/M+*.ttf \
		${PREFIX}/${X_FONTSDIR}/TrueType/
	${MKDIR} ${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-ipattfonts.conf \
		${FILESDIR}/62-fonts-ipattfonts.conf \
		${PREFIX}/etc/fonts/conf.d
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${X11BASE}/bin/fc-cache -f -v ${PREFIX}/${X_FONTSDIR}/TrueType
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
