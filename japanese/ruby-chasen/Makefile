# New ports collection makefile for:	Ruby-ChaSen
# Date created:		1 Mar 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	chasen
PORTVERSION=	1.6
CATEGORIES=	japanese ruby
MASTER_SITES=	http://www.itlb.te.noda.sut.ac.jp/~ikarashi/ruby/
DISTNAME=	${PORTNAME}${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	chasen.0:${PORTSDIR}/japanese/chasen

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-chasen-include="${PREFIX}/include/chasen" \
		--with-chasen-lib="${PREFIX}/lib"
INSTALL_TARGET=	site-install

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/chasen/ja/
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/chasen/ja/
	${MKDIR} ${RUBY_DOCDIR}/chasen/ja
	${INSTALL_DATA} ${WRKSRC}/chasen.html ${RUBY_DOCDIR}/chasen/ja/
.endif

.include <bsd.port.post.mk>
