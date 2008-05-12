# New ports collection makefile for:	Kochi TrueType fonts
# Date created:		6 January 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	kochi-ttfonts
PORTVERSION=	20030809
PORTREVISION=	3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://downloads.sourceforge.jp/efont/5411/ \
		${MASTER_SITE_PORTS_JP}
DISTFILES=	kochi-substitute-${PORTVERSION}.tar.bz2

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Free Japanese TrueType fonts named 'Kochi'

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
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DATADIR}
	${MKDIR} ${LOCALBASE}/${LOCAL_FONTSDIR}/TrueType/
	${LN} -s -f \
		${DATADIR}/*.ttf ${LOCALBASE}/${LOCAL_FONTSDIR}/TrueType/
	${MKDIR} ${LOCALBASE}/${X_FONTSDIR}/TrueType
	${LN} -s -f \
		${DATADIR}/*.ttf ${LOCALBASE}/${X_FONTSDIR}/TrueType/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-kochittfonts.conf \
		${FILESDIR}/62-fonts-kochittfonts.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-kochittfonts.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-kochittfonts.conf
	${LN} -s -f ../conf.avail/62-fonts-kochittfonts.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-kochittfonts.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -f -v ${LOCALBASE}/${X_FONTSDIR}/TrueType
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
