# New ports collection makefile for:   frozen-bubble
# Date created:        2002-10-06
# Whom:                Klaus Goger <klaus.goger@reflex.at>
#
# $FreeBSD$
#

PORTNAME=	frozenbubble
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://zarb.org/~gc/fb//
DISTNAME=	frozen-bubble-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	klaus.goger@reflex.at
COMMENT=	Throw colourful bubbles to build groups and destroy the groups

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SDL_perl.pm:${PORTSDIR}/devel/p5-SDL
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SDL_perl.pm:${PORTSDIR}/devel/p5-SDL

BROKEN=		Incorrectly installs a perllocal.pod file

USE_SDL=	mixer image sdl
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_BZIP2=	yes
MAKE_ENV=	MKDIR="${MKDIR}" \
		TAR="${TAR}"

WRKSRC=		${WRKDIR}/${DISTNAME}/c_stuff/
BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/
USE_PERL5=	yes
PERL_CONFIGURE=	yes

post-patch:
.for file in fb_c_stuff.xs Makefile.PL
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|g'  ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|sdl-config|\${SDL_CONFIG}|g' ${WRKSRC}/Makefile.PL
	@${RM} ${WRKSRC}/lib/FBLE.pm.orig

do-install:
	cd ${WRKSRC}; ${GMAKE} install
	@${INSTALL_SCRIPT} ${BUILD_WRKSRC}/frozen-bubble ${PREFIX}/bin/frozen-bubble.pl

	@${MKDIR} ${PREFIX}/share/frozen-bubble/
	@${MKDIR} ${PREFIX}/share/frozen-bubble/data
	@${MKDIR} ${PREFIX}/share/frozen-bubble/snd
	@${MKDIR} ${PREFIX}/share/frozen-bubble/gfx
	@${MKDIR} ${PREFIX}/share/frozen-bubble/gfx/balls
	@${MKDIR} ${PREFIX}/share/frozen-bubble/gfx/pinguins
	@${MKDIR} ${PREFIX}/share/frozen-bubble/gfx/shoot
	@${MKDIR} ${PREFIX}/share/frozen-bubble/gfx/menu

	@${INSTALL_DATA} ${BUILD_WRKSRC}/data/levels  ${PREFIX}/share/frozen-bubble/data/
	@${INSTALL_DATA} ${BUILD_WRKSRC}/data/plasma.raw  ${PREFIX}/share/frozen-bubble/data/
	@${INSTALL_DATA} ${BUILD_WRKSRC}/gfx/*.png  ${PREFIX}/share/frozen-bubble/gfx/
	@${INSTALL_DATA} ${BUILD_WRKSRC}/gfx/*.gif  ${PREFIX}/share/frozen-bubble/gfx/
	@${INSTALL_DATA} ${BUILD_WRKSRC}/gfx/balls/*.png  ${PREFIX}/share/frozen-bubble/gfx/balls/
	@${INSTALL_DATA} ${BUILD_WRKSRC}/gfx/balls/*.gif  ${PREFIX}/share/frozen-bubble/gfx/balls/
	@${INSTALL_DATA} ${BUILD_WRKSRC}/gfx/pinguins/*.png  ${PREFIX}/share/frozen-bubble/gfx/pinguins/
	@${INSTALL_DATA} ${BUILD_WRKSRC}/gfx/shoot/data ${PREFIX}/share/frozen-bubble/gfx/shoot/
	@${INSTALL_DATA} ${BUILD_WRKSRC}/gfx/shoot/*.png  ${PREFIX}/share/frozen-bubble/gfx/shoot/
	@${INSTALL_DATA} ${BUILD_WRKSRC}/gfx/menu/*.png  ${PREFIX}/share/frozen-bubble/gfx/menu/
	@${INSTALL_DATA} ${BUILD_WRKSRC}/snd/*.wav  ${PREFIX}/share/frozen-bubble/snd/
	@${INSTALL_DATA} ${BUILD_WRKSRC}/snd/*.xm  ${PREFIX}/share/frozen-bubble/snd/

	@printf '#!/bin/sh\nLD_PRELOAD=/usr/lib/libc_r.so perl ${PREFIX}/bin/frozen-bubble.pl $$\@\n' > ${WRKSRC}/frozen-bubble
	@${INSTALL_SCRIPT} ${WRKSRC}/frozen-bubble ${PREFIX}/bin

.include <bsd.port.mk>
