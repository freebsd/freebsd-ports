# New ports collection makefile for:	umefont
# Date created:		25 May 2008
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	umefont
PORTVERSION=	0.0.401
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	ume-font/22212
DISTNAME=	${PORTNAME}-401

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Ume Font, A Free Japanese TrueType font

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
PORTDOCS=	readme.html

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

do-install:
	${MKDIR} ${DATADIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DATADIR}
	${MKDIR} ${LOCALBASE}/${LOCAL_FONTSDIR}/TrueType/
	${LN} -s -f \
		${DATADIR}/*.ttf ${LOCALBASE}/${LOCAL_FONTSDIR}/TrueType/
	${MKDIR} ${LOCALBASE}/${X_FONTSDIR}/TrueType
	${LN} -s -f \
		${DATADIR}/*.ttf ${LOCALBASE}/${X_FONTSDIR}/TrueType/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-umefont.conf \
		${FILESDIR}/62-fonts-umefont.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-umefont.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-umefont.conf
	${LN} -s -f ../conf.avail/62-fonts-umefont.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-umefont.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -f -v ${LOCALBASE}/${X_FONTSDIR}/TrueType
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
