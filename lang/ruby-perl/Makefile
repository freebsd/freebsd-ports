# New ports collection makefile for:	Ruby-perl
# Date created:		11 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	perl
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	lang ruby perl5
MASTER_SITES=	http://www.yoshidam.net/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby extension module to use the functions of Perl from Ruby

BROKEN=		Incorrectly installs a perllocal.pod file

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
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
