# New ports collection makefile for:	Ruby-locale
# Date created:		15 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	locale
PORTVERSION=	0.2
CATEGORIES=	devel ruby
MASTER_SITES=	http://kafka.salem.mass.edu/~yashi/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

#USE_BZIP2=	yes	# only saves 500 bytes..
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/locale
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_EXAMPLESDIR}/locale/
	${MKDIR} ${RUBY_DOCDIR}/locale
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/locale/
.endif

.include <bsd.port.mk>
