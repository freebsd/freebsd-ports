# New ports collection makefile for:	Ruby-strscan
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	strscan
PORTVERSION=	0.5.8
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www1.u-netsurf.ne.jp/~brew/mine/soft/
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_AMSTD=	yes
USE_RUBY_SETUP=	yes

DOCS_EN=	README.en \
		doc.en/changes.html doc.en/index.html \
		doc.en/reference.html doc.en/usage.html
DOCS_JA=	doc.ja/changes.html doc.ja/index.html \
		doc.ja/reference.html doc.ja/usage.html

post-patch:
	${PERL} -i -ne '/\bstrscan\b/ and print' ${WRKSRC}/lib/PATHCONV
	for d in amstd; do ${RM} -rf ${WRKSRC}/lib/$$d; done

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/strscan/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/strscan/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/strscan/ja/
.endfor
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
.include <bsd.port.post.mk>
