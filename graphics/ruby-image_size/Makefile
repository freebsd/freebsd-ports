# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	image_size
PORTVERSION=	0.0.20040618
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.rubycgi.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.${PORTVERSION:E}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library to measure the size of a given image file

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

RUBY_RD_FILES=	readme.ja.rd readme.rd

DOCS_EN=	${RUBY_RD_FILES:N*.ja.rd} \
		${RUBY_RD_HTML_FILES:N*.ja.html}
DOCS_JA=	${RUBY_RD_FILES:M*.ja.rd} \
		${RUBY_RD_HTML_FILES:M*.ja.html}

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/image_size.rb ${STAGEDIR}${RUBY_SITELIBDIR}/

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor

.include <bsd.port.mk>
