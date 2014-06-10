# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	memoize
PORTVERSION=	1.3.1
CATEGORIES=	devel ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	shards
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Method that speeds methods up at the cost of memory

USE_RUBY=	yes
USE_RAKE=	yes
NO_BUILD=	yes

PLIST_FILES=	%%RUBY_SITELIBDIR%%/memoize.rb

PORTEXAMPLES=	example_fibonacci.rb \
		example_memoize.rb
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/memoize.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
.endfor

.include <bsd.port.mk>
