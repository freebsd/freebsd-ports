# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	setup.rb
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/${PORTNAME:R}/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:R}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Common installer script for ruby packages

USE_RUBY=	yes

NO_BUILD=	yes

_SCRIPTS=	setup.rb

DOCS_EN=	doc.en/* NEWS.en Usage_en.txt README.en ChangeLog TODO
DOCS_JA=	doc.ja/* NEWS.ja Usage_ja.txt README.ja

OPTIONS_DEFINE=	DOCS

post-extract:
.for f in ${_SCRIPTS}
	${CP} -p ${WRKSRC}/${f} ${WRKSRC}/ruby-${f}
.endfor

post-patch:
	@${REINPLACE_CMD} 's!%%LOCALBASE%%!${LOCALBASE}!g' \
		${WRKSRC}/ruby-setup.rb

do-install:
.for f in ${_SCRIPTS}
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/ruby-${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor

.include <bsd.port.mk>
