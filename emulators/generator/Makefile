# New ports collection makefile for:   generator
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	generator
PORTVERSION=	0.34
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SEGA Genesis emulator

# apparently the configure script can't handle this
NOT_FOR_ARCHS=	alpha

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		SDL-1.1.5:${PORTSDIR}/devel/sdl12
.if (${MACHINE_ARCH} == "i386")
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.endif

SDL_CONFIG?=    ${LOCALBASE}/bin/sdl11-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk

.if (${MACHINE_ARCH} == "i386")
CONFIGURE_ARGS+=	--with-raze
.else
CONFIGURE_ARGS+=	--with-cmz80
.endif

MAKE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" \
		SDL_CONFIG="${SDL_CONFIG}"
CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" \
		SDL_CONFIG="${SDL_CONFIG}"

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} >= 500035
	@${REINPLACE_CMD} -e \
		's|-malign-loops|-falign-loops|g ; \
		 s|-malign-jumps|-falign-jumps|g ; \
		 s|-malign-functions|-falign-functions|g' ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e \
		's|-malign-loops|-falign-loops|g ; \
		 s|-malign-jumps|-falign-jumps|g ; \
		 s|-malign-functions|-falign-functions|g' ${WRKSRC}/configure
.endif

.if ${OSVERSION} >= 501102
BROKEN=		"Fails to compile due to gcc3.3 preprocessor"
.endif

.include <bsd.port.post.mk>
