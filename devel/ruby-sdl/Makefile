# New ports collection makefile for:	Ruby/SDL
# Date created:		27 Mar 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel graphics audio ruby
MASTER_SITES=	http://www.kmc.kyoto-u.ac.jp/~ohai/rubysdl/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl-devel \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_ttf.2:${PORTSDIR}/graphics/sdl_ttf \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-sdl-config="sdl11-config" \
		--with-cflags="${PTHREAD_CFLAGS}" \
		--with-ldflags="${PTHREAD_LIBS}"
INSTALL_TARGET=	site-install

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500018
BROKEN=	"libc_r conflicts with libc on your system. (Ruby/SDL can be used on 5-CURRENT only)"
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endif

.include <bsd.port.post.mk>
