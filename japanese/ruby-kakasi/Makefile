# New ports collection makefile for:	Ruby-kakasi
# Date created:		16 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	kakasi
PORTVERSION=	000124
PORTREVISION=	1
CATEGORIES=	japanese ruby
MASTER_SITES=	http://www.notwork.org/~gotoken/ruby/p/kakasi/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	kakasi.2:${PORTSDIR}/japanese/kakasi

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS_EN=	ChangeLog	README		wdcnt.html
DOCS_JA=	README.jp

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-patch:
	${PERL} -i -pe 's,/usr/local,${PREFIX},g' ${WRKSRC}/extconf.rb
	${PERL} -i -pe 's,\./(kakasi),$$1,g' ${WRKSRC}/test.rb

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wdcnt ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/kakasi/ja/
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_EXAMPLESDIR}/kakasi/ja/
	${MKDIR} ${RUBY_DOCDIR}/kakasi/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/kakasi/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/kakasi/ja/
.endfor
.endif

.include <bsd.port.post.mk>
