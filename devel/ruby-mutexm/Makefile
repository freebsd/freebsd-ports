# New ports collection makefile for:	Ruby-MutexM
# Date created:		21 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mutexm
PORTVERSION=	1.0
CATEGORIES=	devel ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

# mutexm_test.rb is not really a document but a test suite, however,
# we install this because it's the only English reference so far.
DOCS_EN=	mutexm_test.rb
DOCS_JA=	${RD_DOCS_JA}	${RD_DOCS_JA:S/.rd.ja/.ja.html/}
RD_DOCS_JA=	mutexm.rd.ja

do-build:
.if !defined(NOPORTDOCS)
.for f in ${RD_DOCS_EN} ${RD_DOCS_JA}
	cd ${WRKSRC}; \
	${RUBY_RD} ${f} > ${f:S/.rd.ja/.ja.html/}
.endfor
.endif

do-install:
	@cd ${WRKSRC}; \
	${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/mutexm/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mutexm/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mutexm/ja/
.endfor
.endif

.include <bsd.port.mk>
