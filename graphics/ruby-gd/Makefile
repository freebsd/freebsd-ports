# New ports collection makefile for:	Ruby/gd
# Date created:		27 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	GD
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://kirara.prec.kyoto-u.ac.jp/~tam/GD/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	${PKGNAMESUFFIX_XPM}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

CONFIGURE_ARGS=	--with-gd-include="${LOCALBASE}/include/gd" --with-jpeg \
		--with-freetype
INSTALL_TARGET=	site-install

.include <bsd.port.pre.mk>

# Hmm, GREP and TRUE seem to be defined in the bsd.port.post.mk stage.
.if exists(${LOCALBASE}/bin/gd2topng)
WITH_X11_CHECK!=	ldd ${LOCALBASE}/bin/gd2topng | grep -w 'libX11\.so' || true
.else
WITH_X11_CHECK=		# empty
.endif

.if !empty(WITH_X11_CHECK)
USE_XLIB=	yes
USE_XPM=	yes
PKGNAMESUFFIX_XPM=	+xpm
CONFIGURE_ARGS+=	--with-x-dir="${X11BASE}" --with-xpm
.endif

EXAMPLES_EN=	example.rb	\
		gdtestttf.rb	\
		webpng.rb
DOCS_EN=	Changes		\
		TODO		\
		readme.en	\
		doc/INSTALL.en	\
		doc/manual.css	\
		doc/manual.html	\
		doc/manual.rd	\
		doc/manual_index.html
DOCS_JA=	readme.ja	\
		doc/INSTALL.ja
TUTORIAL_JA=	gd_intro-ja.html	\
		imgs/0.png		\
		imgs/1.png		\
		imgs/256.png		\
		imgs/arc.png		\
		imgs/brush1.png		\
		imgs/brush2.png		\
		imgs/copy.png		\
		imgs/copy_merge.png	\
		imgs/demoin.png		\
		imgs/demoout.png	\
		imgs/line.png		\
		imgs/poly.png		\
		imgs/poly_setPt.png	\
		imgs/rectangle.png	\
		imgs/resolve.png	\
		imgs/string.png		\
		imgs/string2.png	\
		imgs/stringttf1.png	\
		imgs/stringttf2.png	\
		imgs/styled_line.png	\
		imgs/styled_line_transparent.png	\
		imgs/top.png		\
		imgs/xpy.png

post-patch:
	${RUBY} -i -pe 'sub %r:/win98/windows/FONTS:, "${X11BASE}/lib/X11/fonts/TrueType"' ${WRKSRC}/sample/gdtestttf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/gd
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_EXAMPLESDIR}/gd/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/gd/ja/imgs
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/gd/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/gd/ja/
.endfor
.for f in ${TUTORIAL_JA}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${RUBY_DOCDIR}/gd/ja/${f}
.endfor
.endif

.include <bsd.port.post.mk>
