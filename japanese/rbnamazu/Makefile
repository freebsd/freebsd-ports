# New ports collection makefile for:	rbnamazu
# Date created:		18 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rbnamazu
PORTVERSION=	0.3
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	ftp://ftp.namazu.org/pub/namazu/ruby/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	rd2:${PORTSDIR}/textproc/ruby-rdtool
.endif
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/optparse.rb:${PORTSDIR}/devel/ruby-optparse

NO_BUILD=	yes

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

MODULES=	rbnamazu.rb nmzqr.rb nmzqr.tab.rb nmzdoc.rb
RD_DOCS=	rbnamazu.rd.ja rbnamazu.rd.en

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/namazu.rb ${PREFIX}/bin/
	${LN} -sf namazu.rb ${PREFIX}/bin/rbnamazu
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/
.endfor
.if !defined(NOPORTDOCS)
.for f in ${RD_DOCS}
	cd ${WRKSRC}; \
	rd2 ${f} > ${f:S/.rd/.html/}
.endfor
	${MKDIR} ${PREFIX}/share/doc/ruby/rbnamazu/ja
.for f in ${RD_DOCS:S/.rd/.html/:M*.en}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/rbnamazu/
.endfor
.for f in ${RD_DOCS:S/.rd/.html/:M*.ja}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/rbnamazu/ja/
.endfor
.endif

.include <bsd.port.mk>
