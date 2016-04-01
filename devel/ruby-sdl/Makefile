# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	2.1.3.1
PORTREVISION=	4
CATEGORIES=	devel graphics audio ruby
MASTER_SITES=	https://ohai.github.io/rubysdl/archives/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Ruby extension library to use SDL library

LICENSE=	LGPL21

LIB_DEPENDS=	libSGE.so:devel/sdl_sge \
		libSDLSKK.so:devel/sdlskk \
		libsmpeg.so:multimedia/smpeg
RUN_DEPENDS=	rubygem-opengl>=0:graphics/rubygem-opengl

USE_SDL=	mixer image ttf sdl
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-sdl-config="sdl-config" \
		--enable-opengl --linkoglmodule \
		--with-x11-dir="${LOCALBASE}" \
		--disable-pthreads
INSTALL_TARGET=	site-install

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSDIR=	${RUBY_MODDOCDIR}
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}

DOCSRCDIR1=	${WRKSRC}
DOC_FILES_WRKSRC_JA=	NEWS.ja README.ja
DOC_FILES_WRKSRC_EN=	NEWS.en README.en

DOCSRCDIRJA=	${WRKSRC}/doc
DOCSDIRJA=	${RUBY_MODDOCDIR}/doc
DOC_FILESJA=	*.rsd *.rb *ref.html

DOCSRCDIREN=	${WRKSRC}/doc-en
DOCSDIREN=	${RUBY_MODDOCDIR}/doc-en
DOC_FILESEN=	*.rsd *ref.en.html

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/*/sdl_ext.so
	@${REINPLACE_CMD} -e 's|ruby|${LOCALBASE}/bin/ruby|g' ${WRKSRC}/doc/rsd.rb

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
	${INSTALL_DATA} ${DOC_FILES_WRKSRC_JA:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}/ja/
	${INSTALL_DATA} ${DOC_FILES_WRKSRC_EN:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc/ja
	${INSTALL_DATA} ${DOC_FILESJA:S|^|${DOCSRCDIRJA}/|} ${STAGEDIR}${DOCSDIR}/doc/ja/
	${INSTALL_DATA} ${DOC_FILESEN:S|^|${DOCSRCDIREN}/|} ${STAGEDIR}${DOCSDIR}/doc/
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
