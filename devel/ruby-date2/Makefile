# New ports collection makefile for:	Ruby-date2
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	date2
PORTVERSION=	2.5
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.funaba.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

MODULES=	date2.rb date3.rb holiday.rb odate.rb \
		parsedate2.rb parsedate2.ry parsedate3.rb \
		qholiday.rb strftime.rb strptime.rb

DOCS_EN=	MANUAL.en MANUAL.en.rd MANUAL.en.html README.en
DOCS_JA=	MANUAL MANUAL.rd MANUAL.html README
EXAMPLES_EN=	cal.rb daylight.rb goodfriday.rb
EXAMPLES_JA=	ncal.rb

do-install:
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${RUBY_SITELIBDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/date2/ja
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_EXAMPLESDIR}/date2/
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_EXAMPLESDIR}/date2/ja/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/date2/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/date2/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/date2/ja/
.endfor
.endif

.include <bsd.port.mk>
