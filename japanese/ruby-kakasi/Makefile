# New ports collection makefile for:	Ruby-kakasi
# Date created:		16 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	kakasi
PORTVERSION=	020928
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	http://www.notwork.org/~gotoken/ruby/p/kakasi/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	KAKASI module for Ruby

LIB_DEPENDS=	kakasi.3:${PORTSDIR}/japanese/kakasi

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog	README		wdcnt.html
DOCS_JA=	README.jp

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-patch:
	${RUBY} -i -pe 'gsub %r"/usr/local", "${PREFIX}"' ${WRKSRC}/extconf.rb
	${RUBY} -i -pe 'gsub %r"\./(kakasi)", "\\1"' ${WRKSRC}/test.rb

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wdcnt ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja/
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_MODEXAMPLESDIR}/ja/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.post.mk>
