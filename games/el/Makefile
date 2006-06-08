# New ports collection makefile for:   el
# Date created:        25 January 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	el
PORTVERSION=	112
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.berlios.de/pub/elc/ http://el.tfm.ro/
DISTFILES=	${EL_PROG} ${EL_DATA}
EXTRACT_ONLY=	${EL_PROG}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eternal Lands is a free 3D MMORPG

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		cal3d.11:${PORTSDIR}/graphics/cal3d \
		alut.1:${PORTSDIR}/audio/freealut
RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_GNOME=	libxml2
USE_SDL=	sdl net

EL_PROG=	elc_${PORTVERSION}.tgz
EL_DATA=	el_${PORTVERSION}_linux.zip

WRKSRC=		${WRKDIR}/elc

ALL_TARGET=	cal3d
MAKEFILE=	Makefile.bsd

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CFLAGS+=	-DX86_64
.endif

.if ${OSVERSION} < 500000
BROKEN=		"does not compile"
.endif

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

do-install:
	${ECHO} "#!/bin/sh" > ${WRKDIR}/el
	${ECHO} "cd ${DATADIR}; ./el.x86.bsd.bin" >> ${WRKDIR}/el
	${INSTALL_SCRIPT} ${WRKDIR}/el ${PREFIX}/bin

	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/el.x86.bsd.bin ${DATADIR}
	${UNZIP_CMD} ${DISTDIR}/${EL_DATA} -d ${DATADIR}

.include <bsd.port.post.mk>
