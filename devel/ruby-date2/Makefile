# New ports collection makefile for:	Ruby-date2
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	date2
PORTVERSION=	2
CATEGORIES=	devel	# ruby
MASTER_SITES=	http://www.kt.rim.or.jp/~tadf/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

NO_BUILD=	yes

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

MODULES=	date2.rb date3.rb holiday.rb odate.rb \
		parsedate2.rb parsedate2.ry parsedate3.rb \
		qholiday.rb strftime.rb strptime.rb

DOCS_EN=	CHANGES.en MANUAL.en README.en
DOCS_JA=	MANUAL README
EXAMPLES_EN=	cal.rb daylight.rb goodfriday.rb
EXAMPLES_JA=	ncal.rb

do-install:
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${PREFIX}/lib/ruby/site_ruby/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/date2/ja
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${PREFIX}/share/examples/ruby/date2/
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${PREFIX}/share/examples/ruby/date2/ja/
.endfor
	${MKDIR} ${PREFIX}/share/doc/ruby/date2/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/date2/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/date2/ja/
.endfor
.endif

.include <bsd.port.mk>
