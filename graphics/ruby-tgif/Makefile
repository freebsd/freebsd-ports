# New ports collection makefile for:	Ruby/Tgif
# Date created:		6 April 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tgif
PORTVERSION=	20010408
PORTREVISION=	4
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www2s.biglobe.ne.jp/~Nori/ruby/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}-2
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby extension library to draw Tgif graphics

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${TGIF_PORT}:build

USE_GETTEXT=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes

TGIF_PORT=	graphics/tgif-nls

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS=	--with-x-dir="${X11BASE}" \
		--with-ldflags=" `cd ${WRKSRC}/tgif; ${MAKE} -V LDOPTIONS -V LOCAL_LIBRARIES -V LDLIBS -V EXTRA_LOAD_FLAGS | paste -s -`"
INSTALL_TARGET=	site-install

DOCS_EN=	README
DOCS_JA=	ChangeLog.ja	README.ja

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not build on amd64 (missing -fPIC)"
.endif

post-extract:
	${LN} -sf `cd ${PORTSDIR}/${TGIF_PORT}; ${MAKE} -V WRKSRC` ${WRKSRC}/tgif

post-patch:
	${RUBY} -i -pe 'gsub %r|\.\./|, "tgif/"' ${WRKSRC}/extconf.rb ${WRKSRC}/*.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/examples/test??.rb ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/test??_ja.rb ${RUBY_MODEXAMPLESDIR}/ja/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.post.mk>
