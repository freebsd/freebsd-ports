# New ports collection makefile for:	doomlegacy
# Date Created:				10 April 2002
# Whom:				Alexander G. Chetirbock <bock@bock.nnov.ru>
#
# $FreeBSD$

PORTNAME=	doomlegacy
PORTVERSION=	1.32b4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR?=	${PORTNAME}
DISTNAME=	legacy_${FILEVERSION}_src
DISTFILES=	${DIST} ${WADFILE}
EXTRACT_ONLY=	${DIST}

MAINTAINER=	bock@bock.nnov.ru
COMMENT=	DooM Legacy: popular DooM clone!

BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip \
		nasm:${PORTSDIR}/devel/nasm

WADVER=		132b4
WADFILE=	doom3_wad_${WADVER}.zip
FILEVERSION=	132beta4
DIST=		${DISTNAME}${EXTRACT_SUFX}

USE_XLIB=	yes
USE_GMAKE=	yes
USE_MESA=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile
MAKE_ENV+=	FREEBSD=1 PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

# I have no ideas about build status on other platforms
ONLY_FOR_ARCHS=		i386

TARGET_DIR=	${PREFIX}/${PORTNAME}

DATA_FILES=	${WRKDIR}/bin/doom3.wad
PROG_FILES=	${WRKDIR}/bin/llsndserv ${WRKDIR}/bin/r_opengl.so
SGID_FILES=	${WRKDIR}/bin/llxdoom
SGID_ARGS=	-c -s -o root -g kmem -m 2555

post-extract:
	@cd ${WRKDIR} && ${MKDIR} bin && \
	unzip -q ${_DISTDIR}/${WADFILE} -d ${WRKDIR}/bin

do-install:
	${LN} -sf ${WRKSRC}/linux_x/sndserv/linux/llsndserv ${WRKDIR}/bin
	${INSTALL} -d ${TARGET_DIR} && \
	${INSTALL_PROGRAM} ${PROG_FILES} ${TARGET_DIR} && \
	${INSTALL} ${SGID_ARGS} ${SGID_FILES} ${TARGET_DIR} && \
	${INSTALL_DATA} ${DATA_FILES} ${TARGET_DIR} && \
	${INSTALL} -d ${DOCSDIR} && \
	${INSTALL_DATA} ${WRKSRC}/_doc/* ${DOCSDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
