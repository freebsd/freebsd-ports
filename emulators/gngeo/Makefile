# New ports collection makefile for:	gngeo
# Date created:				17 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	gngeo
PORTVERSION=	0.6.4
CATEGORIES=	emulators
MASTER_SITES=	http://m.peponas.free.fr/gngeo/download/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	NeoGeo emulator

RESTRICTED=	The Neo-Geo BIOS can not be redistributed

USE_GMAKE=	yes
USE_SDL=	image sdl
USE_GL=		yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=""
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags` -I${X11BASE}/include" \
		LDFLAGS="`${SDL_CONFIG} --libs`"

OPTIONS=	GUI "Enable GUI support (experimental)" off \
		I386ASM "Use i386 optimization" on \
		RAZE "Use Raze as z80 emulator (only for i386)" on \
		STAR "Use Starscream as 68k emulator (only for i386)" on

MAN1=		gngeo.1

NGBIOS=		neo-geo.rom ng-lo.rom ng-sfix.rom ng-sm1.rom

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}| ; \
			s|-mcpu=$$target_cpu||' \
				${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
# Neo-Geo BIOS
.for f in ${NGBIOS}
	@${INSTALL_DATA} ${DISTDIR}/${f} ${DATADIR}
.endfor

# Examples
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample_gngeorc ${EXAMPLESDIR}/gngeorc

.include <bsd.port.pre.mk>

.for f in ${NGBIOS}
.	if !exists(${DISTDIR}/${DIST_SUBDIR}/${f}) || defined(PACKAGE_BUILDING)
IGNORE?=	Could not find ${DISTDIR}/${DIST_SUBDIR}/${f}. You need to manually download a copy of the Neo-Geo BIOS, extract the files and place them into ${DISTDIR}/${DIST_SUBDIR}. It is available at http://www.ocf.berkeley.edu/~wwu/downloads/neogeo.zip
.	endif
.endfor

.if defined(WITH_I386ASM) || defined(WITH_RAZE) || defined(WITH_STAR)
BUILD_DEPENDS+=		nasm:${PORTSDIR}/devel/nasm
.endif

.if defined(WITH_GUI)
CONFIGURE_ARGS+=	--enable-gui
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.if defined(WITH_I386ASM) && ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386asm
.else
CONFIGURE_ARGS+=	--disable-i386asm
.endif

.if defined(WITH_RAZE) && ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-raze
.else
CONFIGURE_ARGS+=	--enable-mamez80
.endif

.if defined(WITH_STAR) && ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-starscream
.else
CONFIGURE_ARGS+=	--enable-gen68k
.endif

.include <bsd.port.post.mk>
