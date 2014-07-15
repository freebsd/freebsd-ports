# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	2.1.3
PORTREVISION=	2
CATEGORIES=	devel graphics audio ruby
MASTER_SITES=	RUBYFORGE/ruby${PORTNAME}/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Ruby extension library to use SDL library

LICENSE=	LGPL21

LIB_DEPENDS=	libSGE.so:${PORTSDIR}/devel/sdl_sge \
		libSDLSKK.so.2.0:${PORTSDIR}/devel/sdlskk \
		libsmpeg.so:${PORTSDIR}/multimedia/smpeg

RUBY_OPENGL_PORTDIR=	${PORTSDIR}/graphics/ruby-opengl
RUBY_OPENGL_WRKSRC_CMD=	cd ${RUBY_OPENGL_PORTDIR}; ${MAKE} -V WRKSRC

USE_SDL=	mixer image ttf sdl
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-sdl-config="sdl-config" \
		--enable-opengl --linkoglmodule \
		--with-x11-dir="${LOCALBASE}" \
		--disable-pthreads
INSTALL_TARGET=	site-install

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/sdl_ext.so \
		%%RUBY_SITELIBDIR%%/rubysdl_aliases.rb \
		%%RUBY_SITELIBDIR%%/rubysdl_compatible_ver1.rb \
		%%RUBY_SITELIBDIR%%/sdl.rb \
		%%RUBY_SITELIBDIR%%/sdl1_compatible.rb

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSDIR=	${RUBY_MODDOCDIR}
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}

DOCSRCDIR1=	${WRKSRC}
DOC_FILES_WRKSRC_JA=	NEWS.ja README.ja
DOC_FILES_WRKSRC_EN=	NEWS.en README.en

DOCSRCDIRJA=	${WRKSRC}/doc
DOCSDIRJA=	${RUBY_MODDOCDIR}/doc
DOC_FILESJA=	*.rsd *.rb

DOCSRCDIREN=	${WRKSRC}/doc-en
DOCSDIREN=	${RUBY_MODDOCDIR}/doc-en
DOC_FILESEN=	*.rsd

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ruby/site_ruby/1.9/*/sdl_ext.so
	@${REINPLACE_CMD} -e 's|ruby|${LOCALBASE}/bin/ruby|g' ${WRKSRC}/doc/rsd.rb

	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
	${INSTALL_DATA} ${DOC_FILES_WRKSRC_JA:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}/ja/
	${INSTALL_DATA} ${DOC_FILES_WRKSRC_EN:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc/ja
	${INSTALL_DATA} ${DOC_FILESJA:S|^|${DOCSRCDIRJA}/|} ${STAGEDIR}${DOCSDIR}/doc/ja/
	${INSTALL_DATA} ${DOC_FILESEN:S|^|${DOCSRCDIREN}/|} ${STAGEDIR}${DOCSDIR}/doc/

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
