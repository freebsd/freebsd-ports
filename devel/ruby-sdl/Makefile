# New ports collection makefile for:	Ruby/SDL
# Date created:		27 Mar 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	devel graphics audio ruby
MASTER_SITES=	http://www.kmc.gr.jp/~ohai/rubysdl/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby extension library to use SDL library

BUILD_DEPENDS=	${NONEXISTENT}:${RUBY_OPENGL_PORTDIR}:patch

RUBY_OPENGL_PORTDIR=	${.CURDIR}/../../graphics/ruby-opengl
RUBY_OPENGL_WRKSRC_CMD=	cd ${RUBY_OPENGL_PORTDIR}; ${MAKE} -V WRKSRC

USE_SDL=	mixer image ttf sdl
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-sdl-config="sdl11-config" \
		--enable-opengl --linkoglmodule \
		--with-x11-dir="${X11BASE}"
INSTALL_TARGET=	site-install

RUBY_RD_FILES=	rubysdl_doc.en.rd \
		rubysdl_doc.rd

DOCS_EN=	NEWS.en README.en rubysdl_const_list.txt \
		${RUBY_RD_FILES:M*.en.rd} \
		${RUBY_RD_HTML_FILES:M*.en.html}
DOCS_JA=	NEWS.ja README.ja \
		${RUBY_RD_FILES:N*.en.rd} \
		${RUBY_RD_HTML_FILES:N*.en.html}

.include <bsd.port.pre.mk>

post-extract:
	dir=`${RUBY_OPENGL_WRKSRC_CMD}`; \
	for f in rbogl.h rbogl.c ogl.c glu.c; do \
		${LN} -fs $$dir/$$f ${WRKSRC}/; \
	done

post-patch:
	${RUBY} -i -pe '/require \x27mkmf\x27/ and $$_ += "dir_config(\x27x11\x27)\n"' \
		${WRKSRC}/${RUBY_EXTCONF}

post-install: doc-install

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.post.mk>
