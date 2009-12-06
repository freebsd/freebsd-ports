# New ports collection makefile for:	IPA+Mona TrueType fonts
# Date created:		15 February, 2009
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	font-mona-ipa
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.geocities.jp/ipa_mona/
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
PORTDOCS=	COPYING.font.ja README_ipamona.txt

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

do-install:
	${MKDIR} ${DATADIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 0555
	${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${CHMOD} 0444
	${CP} -R ${WRKSRC}/* ${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/TTF/
	${LN} -s -f \
		${DATADIR}/fonts/ipa*-mona.ttf \
		${LOCALBASE}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${LOCALBASE}/${X_FONTSDIR}/TTF
	${LN} -s -f \
		${DATADIR}/fonts/ipa*-mona.ttf \
		${LOCALBASE}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-mona-ipa.conf \
		${FILESDIR}/62-fonts-mona-ipa.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-mona-ipa.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-mona-ipa.conf
	${LN} -s -f ../conf.avail/62-fonts-mona-ipa.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-mona-ipa.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/fonts && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -f -v ${LOCALBASE}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
