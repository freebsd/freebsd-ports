# New ports collection makefile for:	doomlegacy
# Date Created:				10 April 2002
# Whom:				Alexander G. Chetirbock <bock@bock.nnov.ru>
#
# $FreeBSD$

PORTNAME=	doomlegacy
PORTVERSION=	142
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	legacy_${PORTVERSION}_src
DISTFILES=	${DIST} ${WADFILE}
DIST=		${DISTNAME}${EXTRACT_SUFX}
WADFILE=	legacy_dat.zip
EXTRACT_ONLY=	${DIST}

MAINTAINER=	bock@bock.nnov.ru
COMMENT=	DooM Legacy: popular DooM clone!

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_XLIB=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	mixer

WRKSRC=		${WRKDIR}/doomlegacy_${PORTVERSION}_src
MAKEFILE=	makefile
MAKE_ENV+=	FREEBSD=1 FBSD_SDL=1 PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

# I have no ideas about build status on other platforms
ONLY_FOR_ARCHS=		i386

TARGET_DIR=	${PREFIX}/${PORTNAME}

DATA_FILES=	${WRKDIR}/bin/legacy.dat
PROG_FILES=	${WRKDIR}/bin/llsndserv ${WRKDIR}/bin/r_opengl.so
SGID_FILES=	${WRKDIR}/bin/lsdldoom
SGID_ARGS=	-c -s -o root -g kmem -m 2555
DOC_FILES=	*.html *.txt *.cfg README_SDL copying

post-extract:
	@${MKDIR} ${WRKDIR}/bin
	${UNZIP_CMD} -q ${DISTDIR}/${WADFILE} -d ${WRKDIR}/bin

post-patch:
	@${SED} -e "s|%%INSTALLDIR%%|${PREFIX}/${PORTNAME}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/bin/wrapper.sh

pre-build:
	cd ${WRKSRC}/linux_x/sndserv && ${GMAKE} clean

post-build:
	@${LN} -s ${WRKSRC}/linux_x/sndserv/linux/llsndserv ${WRKDIR}/bin

do-install:
	${INSTALL} -d ${TARGET_DIR}
	${INSTALL_PROGRAM} ${PROG_FILES} ${TARGET_DIR}
	${INSTALL} ${SGID_ARGS} ${SGID_FILES} ${TARGET_DIR}
	${INSTALL_DATA} ${DATA_FILES} ${TARGET_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/bin/wrapper.sh ${TARGET_DIR}/legacy.sh
	@${LN} -s ${TARGET_DIR}/legacy.sh ${PREFIX}/bin/legacy

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/_doc/${file} ${DOCSDIR}
.endfor
.endif
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.mk>
