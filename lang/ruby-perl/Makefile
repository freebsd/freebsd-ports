# New ports collection makefile for:	Ruby-perl
# Date created:		11 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	perl
PORTVERSION=	0.2.7
CATEGORIES=	lang ruby perl5
MASTER_SITES=	http://www.yoshidam.net/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_PERL5=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-libperl=/usr/lib/libperl.so
INSTALL_TARGET=	site-install

EXAMPLES=	htmlparse.rb	http.rb		perllib.rb	ping.rb \
		test.rb		xmlparser.rb

do-configure:
	@cd ${WRKSRC}/Ruby; \
	${PERL} Makefile.PL

post-build:
	@cd ${WRKSRC}/Ruby; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE}

post-install:
	@cd ${WRKSRC}/Ruby; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/perl
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${RUBY_EXAMPLESDIR}/perl/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/perl/ja
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_DOCDIR}/perl/ja/
.endif

.include <bsd.port.mk>
