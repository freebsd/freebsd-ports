# New ports collection makefile for:	Kochi TrueType fonts
# Date created:		6 January 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	font-kochi
PORTVERSION=	20030809
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://downloads.sourceforge.jp/efont/5411/ \
		${MASTER_SITE_PORTS_JP}
DISTNAME=	kochi-substitute-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Kochi Japanese TrueType font

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR} \
		DATADIR=share/${PORTNAME}
WRKSRC=		${WRKDIR}/kochi-substitute-${PORTVERSION}

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

PORTDOCS=	README.ja COPYING docs

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DATADIR}
	${MKDIR} ${LOCALBASE}/${LOCAL_FONTSDIR}/TTF/
	${LN} -s -f \
		${DATADIR}/*.ttf ${LOCALBASE}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${LOCALBASE}/${X_FONTSDIR}/TTF
	${LN} -s -f \
		${DATADIR}/*.ttf ${LOCALBASE}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-kochi.conf \
		${FILESDIR}/62-fonts-kochi.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-kochi.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-kochi.conf
	${LN} -s -f ../conf.avail/62-fonts-kochi.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-kochi.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -s -f -v ${LOCALBASE}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
