# New ports collection makefile for:	rbnamazu
# Date created:		18 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rbnamazu
PORTVERSION=	0.4
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	ftp://ftp.namazu.org/pub/namazu/ruby/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/optparse.rb:${PORTSDIR}/devel/ruby-optparse

USE_RUBY=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

NO_BUILD=	yes

MODULES=	rbnamazu.rb nmzqr.rb nmzqr.tab.rb nmzdoc.rb
RD_DOCS=	rbnamazu.rd.ja rbnamazu.rd.en

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/namazu.rb ${PREFIX}/bin/
	${LN} -sf namazu.rb ${PREFIX}/bin/rbnamazu
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}
.endfor
.if !defined(NOPORTDOCS)
.for f in ${RD_DOCS}
	cd ${WRKSRC}; \
	${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor
	${MKDIR} ${RUBY_DOCDIR}/rbnamazu/ja
.for f in ${RD_DOCS:S/.rd/.html/:M*.en}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rbnamazu/
.endfor
.for f in ${RD_DOCS:S/.rd/.html/:M*.ja}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rbnamazu/ja/
.endfor
.endif

.include <bsd.port.mk>
