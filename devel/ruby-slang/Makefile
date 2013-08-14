# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	slang
PORTVERSION=	0.52
CATEGORIES+=	devel ruby
MASTER_SITES=	LOCAL/fenner/ruby-contrib
DISTNAME=	${PORTNAME}lib-${PORTVERSION:}-1m
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	S-Lang extension module for Ruby

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang


USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}lib
CONFIGURE_ARGS=	--with-slang-include="${LOCALBASE}/include/slang" \
		--with-slang-lib="${LOCALBASE}/lib"
INSTALL_TARGET=	site-install

EXAMPLES_EN=	fm.rb		smgtest.rb	urlview.rb
EXAMPLES_JA=	pager.rb
DOCS_EN=	README		changes.txt
DOCS_JA=	README.euc

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif

.if defined(PKGNAMEPREFIX)
PKGNAMEPREFIX:= ${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}
.else
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/ja/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.post.mk>
