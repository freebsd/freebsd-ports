# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	locale
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple Ruby module that provides setlocale(3)

BROKEN=		unfetchable
CONFLICTS=	${PKGNAMEPREFIX}locale2-[0-9]*

#USE_BZIP2=	yes	# only saves 500 bytes..
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${RUBY_MODDOCDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/

.include <bsd.port.mk>
