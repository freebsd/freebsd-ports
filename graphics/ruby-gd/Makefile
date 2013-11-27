# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	gd
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.daifukuya.com/archive/kagemai/lib/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	${PKGNAMESUFFIX_XPM}
DISTNAME=	ruby-GD-0.7.4
DIST_SUBDIR=	ruby

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Ruby extension library to use Thomas Boutell's gd library

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2

NEED_ROOT=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

RUBY_MODNAME=	${PORTNAME:L}

CONFIGURE_ARGS=	--with-gd-lib="${LOCALBASE}/lib" \
		--with-jpeg \
		--with-ttf \
		--with-freetype
INSTALL_TARGET=	site-install

CONFIGURE_ARGS+=	--enable-gd2_0 \
		--with-gd-include="${LOCALBASE}/include"
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd

.include <bsd.port.options.mk>

# Hmm, GREP and TRUE seem to be defined in the bsd.port.post.mk stage.
.if exists(${LOCALBASE}/bin/gd2topng)
WITH_X11_CHECK!=	ldd ${LOCALBASE}/bin/gd2topng | grep -w 'libX11\.so' || ${ECHO_CMD}
.else
WITH_X11_CHECK=		# empty
.endif

.if !empty(WITH_X11_CHECK)
USE_XORG=	xpm x11
PKGNAMESUFFIX_XPM=	+xpm
CONFIGURE_ARGS+=	--with-X11-dir="${LOCALBASE}" --with-xpm
.endif

EXAMPLES_EN=	example.rb	\
		gdtestttf.rb	\
		webpng.rb
DOCS_EN=	Changes		\
		TODO		\
		readme.en	\
		doc/INSTALL.en	\
		doc/manual.html	\
		doc/manual.rd	\
		doc/manual_index.html
DOCS_JA=	readme.ja	\
		doc/INSTALL.ja

post-patch:
	${RUBY} -i -pe 'sub %r:/win98/windows/FONTS:, "${LOCALBASE}/lib/X11/fonts/TrueType"' ${WRKSRC}/sample/gdtestttf.rb
	${RUBY} -i -pe 'sub %r:%%GD%%:, "gd"' ${WRKSRC}/extconf.rb

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
