# New ports collection makefile for:	Sazanami TrueType fonts
# Date created:		19 June 2004
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	font-sazanami
PORTVERSION=	20040629
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	efont/10087
DISTNAME=	${PORTNAME:C/font-//}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Sazanami Japanese TrueType fonts

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
PORTDOCS=	README doc
WRKSRC=		${WRKDIR}/sazanami-${PORTVERSION}

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DATADIR}
	${MKDIR} ${LOCALBASE}/${LOCAL_FONTSDIR}/TTF
	${LN} -s -f \
		${DATADIR}/*.ttf ${LOCALBASE}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${LOCALBASE}/${X_FONTSDIR}/TTF
	${LN} -s -f \
		${DATADIR}/*.ttf ${LOCALBASE}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-sazanami.conf \
		${FILESDIR}/62-fonts-sazanami.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-sazanami.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-sazanami.conf
	${LN} -s -f ../conf.avail/62-fonts-sazanami.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-sazanami.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -s -f -v ${LOCALBASE}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
