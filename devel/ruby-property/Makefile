# New ports collection makefile for:    Ruby-property
# Date created:         7 Aug 2000
# Whom:                 Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	property
PORTVERSION= 	19990308
CATEGORIES=	devel	# ruby
MASTER_SITES=	http://www.ueda.info.waseda.ac.jp/~igarashi/ruby/
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

post-patch:
	${PERL} -i -pe 's|rubyapi.css|../rubyapi.css|g' ${WRKSRC}/Properties-ja.html

do-install:
	${INSTALL_DATA} ${WRKSRC}/property.rb ${PREFIX}/lib/ruby/${RUBY_VER}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/property/ja
.for f in property-example.rb test.default property.README Properties.html rubyapi.css
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/property
.endfor
.for f in property.README.ja Properties-ja.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/property/ja
.endfor
.endif

.include <bsd.port.mk>
