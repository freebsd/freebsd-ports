# New ports collection makefile for:	doomlegacy
# Date Created:				10 April 2002
# Whom:				Alexander G. Chetirbock <bock@bock.nnov.ru>
#
# $FreeBSD$

PORTNAME=	doomlegacy
PORTVERSION=	142
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/DooM%20Legacy%20source%20code/1.42
DISTNAME=	legacy_${PORTVERSION}_src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${WADFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	DooM Legacy: popular DooM clone!

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

USE_GL=		yes
USE_GMAKE=	yes
USE_SDL=	mixer sdl
MAKEFILE=	makefile
MAKE_ENV=	FREEBSD=1 FBSD_SDL=1 PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
WRKSRC=		${WRKDIR}/doomlegacy_${PORTVERSION}_src

OPTIONS=	X86_ASM "Enable use of x86 assembly code" on

DATADIR=	${PREFIX}/lib/${PORTNAME}
SUB_FILES=	legacy

WADFILE=	legacy_dat.zip

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_X86_ASM) && ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
MAKE_ARGS+=	USEASM=1
.endif

post-extract:
	@${UNZIP_CMD} -q ${DISTDIR}/${WADFILE} -d ${WRKDIR}/bin

post-patch:
	@${REINPLACE_CMD} -e \
		's|-I/usr/local/include/SDL11|`${SDL_CONFIG} --cflags`|; \
		 s|-lSDL-1\.1|`${SDL_CONFIG} --libs`|; \
		 s|/usr/local|${LOCALBASE}|; \
		 s|/usr/X11R6|${LOCALBASE}|' \
		 ${WRKSRC}/${MAKEFILE}

pre-build:
	@cd ${WRKSRC}/linux_x/sndserv && ${GMAKE} clean

post-build:
	@${LN} -sf ${WRKSRC}/linux_x/sndserv/linux/llsndserv ${WRKDIR}/bin

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKDIR}/bin && ${INSTALL_PROGRAM} llsndserv r_opengl.so ${DATADIR}
	${INSTALL} -c -s -o root -g kmem -m 2555 ${WRKDIR}/bin/lsdldoom \
		${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/bin/legacy.dat ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/legacy ${PREFIX}/bin/${PORTNAME}
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for f in *.html *.txt *.cfg README_SDL copying
	${INSTALL_DATA} ${WRKSRC}/_doc/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
