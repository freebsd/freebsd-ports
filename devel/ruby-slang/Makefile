# New ports collection makefile for:	Ruby-slang (slanglib)
# Date created:		23 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	slang
PORTVERSION=	0.52
CATEGORIES+=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	contrib
DISTNAME=	${PORTNAME}lib-${PORTVERSION:}-1m
DIST_SUBDIR=	ruby

MAINTAINER?=	knu@FreeBSD.org
COMMENT?=	S-Lang extension module for Ruby

.if defined(WITH_JAPANESE)
LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang
.else
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang
.endif

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
