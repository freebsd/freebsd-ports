# New ports collection makefile for:	Ruby-kakasi
# Date created:		16 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	kakasi
PORTVERSION=	000124
CATEGORIES=	japanese ruby
MASTER_SITES=	http://www.notwork.org/~gotoken/ruby/p/kakasi/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	kakasi.2:${PORTSDIR}/japanese/kakasi
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

INSTALL_TARGET=	site-install

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

DOCS_EN=	ChangeLog	README		wdcnt.html
DOCS_JA=	README.jp

post-patch:
	${PERL} -i -pe 's,/usr/local,${PREFIX},g' ${WRKSRC}/extconf.rb
	${PERL} -i -pe 's,\./(kakasi),$$1,g' ${WRKSRC}/test.rb

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wdcnt ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/kakasi/ja/
	${INSTALL_DATA} ${WRKSRC}/test.rb ${PREFIX}/share/examples/ruby/kakasi/ja/
	${MKDIR} ${PREFIX}/share/doc/ruby/kakasi/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/kakasi/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/kakasi/ja/
.endfor
.endif

.include <bsd.port.mk>
