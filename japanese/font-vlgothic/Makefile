# New ports collection makefile for:	VLGothic fotns
# Date created:		31 Oct 2006
# Whom:			NIIMI Satoshi <sa2c@sa2c.net>
#
# $FreeBSD$
#

PORTNAME=	font-vlgothic
PORTVERSION=	20090422
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	vlgothic/38942
DISTNAME=	VLGothic-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	VLGothic Japanese TrueType fonts

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
PORTDOCS=	Changelog LICENSE LICENSE.en LICENSE_E.mplus LICENSE_J.mplus \
		README README.sazanami README_J.mplus
WRKSRC=		${WRKDIR}/VLGothic

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/*.ttf \
		${LOCALBASE}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${LOCALBASE}/${X_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/*.ttf \
		${LOCALBASE}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-vlgothic.conf \
		${FILESDIR}/62-fonts-vlgothic.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-vlgothic.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-vlgothic.conf
	${LN} -s -f ../conf.avail/62-fonts-vlgothic.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-vlgothic.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -s -f -v ${LOCALBASE}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
