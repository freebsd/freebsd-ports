# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rica
PORTVERSION=	0.10
CATEGORIES=	irc ruby
MASTER_SITES=	http://www.koka-in.org/%7Ezophos/lib/rica/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Another IRC client framework for Ruby

USES=		tar:bzip2
USE_RUBY=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MODULES=	rica.rb \
		ctcpresponder.rb \
		connectiondiag.rb \
		logholder.rb

DOCS=		CHANGES	README	classes_and_methods.txt	event.lst *.png
EXAMPLES=	erica.* ricaco.rb rica-example.rb

OPTIONS_DEFINE=	DOCS EXAMPLES

DEPRECATED=	Upstream no longer active
EXPIRATION_DATE=	2017-01-28

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_SITELIBDIR}/
.endfor
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
