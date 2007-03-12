# New ports collection makefile for:	doomlegacy
# Date Created:				10 April 2002
# Whom:				Alexander G. Chetirbock <bock@bock.nnov.ru>
#
# $FreeBSD$

PORTNAME=	doomlegacy
PORTVERSION=	142
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	legacy_${PORTVERSION}_src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${WADFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DooM Legacy: popular DooM clone!

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

USE_GL=		yes
USE_GMAKE=	yes
USE_SDL=	mixer sdl
USE_XLIB=	yes

OPTIONS=	X86_ASM "Enable use of x86 assembly code" on

WRKSRC=		${WRKDIR}/doomlegacy_${PORTVERSION}_src
MAKEFILE=	makefile
MAKE_ENV+=	FREEBSD=1 FBSD_SDL=1 PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

SUB_FILES=	legacy
WADFILE=	legacy_dat.zip
DATADIR=	${PREFIX}/lib/${PORTNAME}

post-extract:
	${UNZIP_CMD} -q ${DISTDIR}/${WADFILE} -d ${WRKDIR}/bin

post-patch:
	@${REINPLACE_CMD} -e \
		's|-I/usr/local/include/SDL11|`${SDL_CONFIG} --cflags`|; \
		 s|-lSDL-1\.1|`${SDL_CONFIG} --libs`|; \
		 s|/usr/local|${LOCALBASE}|; \
		 s|/usr/X11R6|${X11BASE}|' \
		 ${WRKSRC}/${MAKEFILE}

pre-build:
	cd ${WRKSRC}/linux_x/sndserv && ${GMAKE} clean

post-build:
	@${LN} -s ${WRKSRC}/linux_x/sndserv/linux/llsndserv ${WRKDIR}/bin

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/llsndserv ${WRKDIR}/bin/r_opengl.so \
		${DATADIR}
	${INSTALL} -c -s -o root -g kmem -m 2555 ${WRKDIR}/bin/lsdldoom \
		${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/bin/legacy.dat ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/legacy ${PREFIX}/bin/${PORTNAME}

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.   for f in *.html *.txt *.cfg README_SDL copying
	${INSTALL_DATA} ${WRKSRC}/_doc/${f} ${DOCSDIR}
.   endfor
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_X86_ASM) && ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
MAKE_ARGS+=	USEASM=1
.endif

.include <bsd.port.post.mk>
