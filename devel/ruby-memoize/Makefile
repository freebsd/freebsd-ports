# New ports collection makefile for:	ruby-memoize
# Date created:		2011-04-23
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	memoize
PORTVERSION=	1.3.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/61790/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|tota/memoize|}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A method that speeds methods up at the cost of memory

FETCH_ARGS=	-Fpr

USE_RUBY=	yes
USE_RAKE=	yes
NO_BUILD=	yes

PLIST_FILES=	%%RUBY_SITELIBDIR%%/memoize.rb

PORTEXAMPLES=	example_fibonacci.rb \
		example_memoize.rb
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/memoize.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_MODEXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
