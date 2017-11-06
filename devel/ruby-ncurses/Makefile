# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	ncurses
PORTVERSION=	1.2.4
CATEGORIES=	devel ruby
MASTER_SITES=	SF/ncurses-ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	saurbier@math.uni-bielefeld.de
COMMENT=	Ruby interface to ncurses

USES=	tar:bzip2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

BROKEN=	checksum mismatch

INSTALL_TARGET=	site-install

DOCS=		COPYING Changes README THANKS TODO

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/

.include <bsd.port.mk>
