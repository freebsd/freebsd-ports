# New ports collection makefile for:	Sazanami TrueType fonts
# Date created:		19 June 2004
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	sazanami-ttf
PORTVERSION=	20040629
PORTREVISION=	4
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	efont/10087
DISTNAME=	${PORTNAME:S/-ttf$//}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Free Japanese TrueType fonts named 'Sazanami'

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
NO_BUILD=	yes

MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR} \
		LOCALFONTSDIR=${LOCALBASE}/${LOCALFONTSDIR}

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR} \
		DATADIR=share/${PORTNAME}
WRKSRC=		${WRKDIR}/sazanami-${PORTVERSION}

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

PORTDOCS=	README doc

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
	${INSTALL_DATA} ${FILESDIR}/20-unhint-sazanami-ttf.conf \
		${FILESDIR}/62-fonts-sazanami-ttf.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-sazanami-ttf.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-sazanami-ttf.conf
	${LN} -s -f ../conf.avail/62-fonts-sazanami-ttf.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-sazanami-ttf.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -f -v ${LOCALBASE}/${X_FONTSDIR}/TrueType
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
