# New ports collection makefile for:   el
# Date created:        25 January 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	el
PORTVERSION=	101
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.berlios.de/pub/elc/ http://el.tfm.ro/
DISTFILES=	${EL_PROG} ${EL_DATA}
EXTRACT_ONLY=	${EL_PROG}

MAINTAINER=	jannisan@t-online.de
COMMENT=	Eternal Lands is a free 3D MMORPG

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		vorbis.3:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_SDL=	sdl net

EL_PROG=	elc_${PORTVERSION}.tgz
EL_DATA=	el_${PORTVERSION}.zip

WRKSRC=		${WRKDIR}/elc

ALL_TARGET=	el.x86.bsd.bin
MAKEFILE=	Makefile.bsd

do-install:
	${ECHO} "#!/bin/sh" > ${WRKDIR}/el
	${ECHO} "cd ${DATADIR}; ./el.x86.bsd.bin" >> ${WRKDIR}/el
	${INSTALL_SCRIPT} ${WRKDIR}/el ${PREFIX}/bin

	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/el.x86.bsd.bin ${DATADIR}
	${UNZIP_CMD} ${DISTDIR}/${EL_DATA} -d ${DATADIR}

.include <bsd.port.mk>
