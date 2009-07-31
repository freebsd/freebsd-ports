# New ports collection makefile for:	Ruby/gd
# Date created:		27 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	GD
PORTVERSION=	0.7.4
PORTREVISION=	7
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.daifukuya.com/archive/kagemai/lib/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	${PKGNAMESUFFIX_XPM}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Ruby extension library to use Thomas Boutell's gd library

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

RUBY_MODNAME=	${PORTNAME:L}

CONFIGURE_ARGS=	--with-gd-lib="${LOCALBASE}/lib" \
		--with-jpeg \
		--with-freetype
INSTALL_TARGET=	site-install

CONFIGURE_ARGS+=	--enable-gd2_0 \
		--with-gd-include="${LOCALBASE}/include"
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd

.include <bsd.port.pre.mk>

# Hmm, GREP and TRUE seem to be defined in the bsd.port.post.mk stage.
.if exists(${LOCALBASE}/bin/gd2topng)
WITH_X11_CHECK!=	ldd ${LOCALBASE}/bin/gd2topng | grep -w 'libX11\.so' || true
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
.if defined(WITH_GD1)
	${RUBY} -i -pe 'sub %r:%%GD%%:, "gd1"' ${WRKSRC}/extconf.rb
.else
	${RUBY} -i -pe 'sub %r:%%GD%%:, "gd"' ${WRKSRC}/extconf.rb
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.post.mk>
