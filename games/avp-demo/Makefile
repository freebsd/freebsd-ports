# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	avp-demo
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.stasyan.com/devel/distfiles/
DISTFILES=	avp_git_20090911.tar.gz avp_data_a03.tar.gz

MAINTAINER=	devel@stasyan.com
COMMENT=	Aliens versus predator unofficial port from icculus.org

USE_SDL=	mixer sdl
USES=		gmake openal pkgconfig
USE_GL=		gl

WRKSRC=		${WRKDIR}
BUILD_WRKSRC=	${WRKDIR}/avp_git

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !(${ARCH} == i386 || ${ARCH} == pc98)
BROKEN=		does not compile
.endif

do-install:
#Install program and doc
		${INSTALL_PROGRAM} ${BUILD_WRKSRC}/avp ${PREFIX}/bin/avp
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${BUILD_WRKSRC}/LICENSE ${DOCSDIR}/LICENSE
		${INSTALL_DATA} ${BUILD_WRKSRC}/README ${DOCSDIR}/README
.endif
#Install data files from Alien demo
		${MKDIR} ${DATADIR}
		${MKDIR} ${DATADIR}/avp_huds
		${MKDIR} ${DATADIR}/avp_rifs
		${MKDIR} ${DATADIR}/fastfile
.		for f in alien.rif alien_hud.rif hnpc_civvie.rif hnpcmarine.rif sentry.rif
		    ${INSTALL_DATA} ${WRKDIR}/avp/avp_huds/${f} ${DATADIR}/avp_huds/${f}
.		endfor
		${INSTALL_DATA} ${WRKDIR}/avp/avp_rifs/temple.rif ${DATADIR}/avp_rifs/temple.rif
.		for f in common.ffl ffinfo.txt marsound.dat snd15.ffl snd30.ffl tex1.ffl tex15.ffl tex26.ffl tex27.ffl tex30.ffl tex32.ffl tex34.ffl tex38.ffl tex40.ffl tex43.ffl snd27.ffl
		    ${INSTALL_DATA} ${WRKDIR}/avp/fastfile/${f} ${DATADIR}/fastfile/${f}
.		endfor
		${INSTALL_DATA} ${WRKDIR}/avp/language.txt ${DATADIR}/language.txt

post-install:
		${SED} -e "/%%DATADIR%%/s//${DATADIR:S/\//\\\//g}/g" ${PKGMESSAGE};

.include <bsd.port.post.mk>
