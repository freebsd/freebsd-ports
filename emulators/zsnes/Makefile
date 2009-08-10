# New ports collection makefile for:	zsnes
# Date created:				Fri May  4 13:10:11 CEST 2001
# Whom:					Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	zsnes
PORTVERSION=	1.51
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	SF
DISTNAME=	zsnes${PORTVERSION:S/.//}src

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Intel x86 only Super Nintendo Entertainment System (SNES) Emulator

# This must be >= 0.98!
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	non-portable, for a portable emulator see emulators/snes9x

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/./_/}/src

OPTIONS=	X11 "Enable X11 video driver" on \
		OPENGL "Enable OpenGL video driver" off \
		DEBUGGER "Enable ZSNES debugger" off \
		JMA "Enable JMA support" on \
		LIBAO "Enable libao support" off

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-cpucheck
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		zsnes.1
PLIST_FILES=	bin/zsnes

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602000
IGNORE=		needs zlib >= 1.2.3, it is available on FreeBSD >= 6.2
.endif

.if defined(WITH_DEBUGGER)
CONFIGURE_ARGS+=	--enable-debugger
.else
CONFIGURE_ARGS+=	--disable-debugger
.endif

.if defined(WITH_JMA)
CONFIGURE_ARGS+=	--enable-jma
.else
CONFIGURE_ARGS+=	--disable-jma
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PKGNAMESUFFIX=	-nox11
.else
CONFIGURE_ARGS+=	--with-x
.endif

.if defined(WITH_OPENGL)
USE_GL=		yes
CONFIGURE_ARGS+=	--enable-opengl
.else
CONFIGURE_ARGS+=	--disable-opengl
.endif

.if defined(WITH_LIBAO)
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao
CONFIGURE_ARGS+=	--enable-libao
.else
CONFIGURE_ARGS+=	--disable-libao
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|@CXX@ @CFLAGS@ -o|@CXX@ @CXXFLAGS@ @CPPFLAGS@ -o|g ; \
		 s|@CC@ @CFLAGS@ -o|@CC@ @CFLAGS@ @CPPFLAGS@ -o|g' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -i "" -e \
		's|-O3||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zsnes ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/linux/zsnes.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
