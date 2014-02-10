# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	cygne-sdl
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://sdlemu.ngemu.com/OpenProjects/
DISTNAME=	Cygne-SDL-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL port of Cygne, a free Bandai Wonderswan emulator

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-02-10

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/Cygne-SDL-${PORTVERSION}/src

USE_SDL=	sdl

PLIST_FILES=	bin/cygne

OPTIONS_DEFINE_i386=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT_i386=	OPTIMIZED_CFLAGS
OPTIMIZED_CFLAGS_CFLAGS=\
		-fomit-frame-pointer -fexpensive-optimizations \
		-funroll-loops -funroll-all-loops -fschedule-insns2 \
		-fstrength-reduce -malign-double -mfancy-math-387 \
		-ffast-math -fforce-addr

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
USE_GCC=	any
.endif

post-patch:
	${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} cygne ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.post.mk>
