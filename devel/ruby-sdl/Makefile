# New ports collection makefile for:	Ruby/SDL
# Date created:		27 Mar 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	0.7
CATEGORIES=	devel graphics audio ruby
MASTER_SITES=	http://www.kmc.kyoto-u.ac.jp/~ohai/rubysdl/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${RUBY_OPENGL_PORTDIR}:patch
LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

RUBY_OPENGL_PORTDIR=	${.CURDIR}/../../graphics/ruby-opengl
RUBY_OPENGL_WRKSRC_CMD=	cd ${RUBY_OPENGL_PORTDIR} && ${MAKE} -V WRKSRC

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

CONFIGURE_ARGS=	--with-sdl-config="sdl11-config" \
		--enable-opengl --linkoglmodule \
		--with-x11-dir="${X11BASE}"
INSTALL_TARGET=	site-install

RD_DOCS_EN=	rubysdl_doc.en.rd
RD_DOCS_JA=	rubysdl_doc.rd

DOCS_EN=	README.en ${RD_DOCS_EN} ${RD_DOCS_EN:S/.rd$/.html/} rubysdl_const_list.txt
DOCS_JA=	README.ja ${RD_DOCS_JA} ${RD_DOCS_JA:S/.rd$/.html/}

post-extract:
	dir=`${RUBY_OPENGL_WRKSRC_CMD}`; \
	for f in rbogl.h rbogl.c ogl.c glu.c; do \
		${LN} -fs $$dir/$$f ${WRKSRC}/; \
	done

post-patch:
	${RUBY} -i -pe '/require \x27mkmf\x27/ and $$_ += "dir_config(\x27x11\x27)\n"' \
		${WRKSRC}/${RUBY_EXTCONF}

post-build:
.if !defined(NOPORTDOCS)
.for f in ${RD_DOCS_EN} ${RD_DOCS_JA}
	@cd ${WRKSRC} && ${RUBY_RD} ${f} > ${f:S/.rd$/.html/}
.endfor
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
