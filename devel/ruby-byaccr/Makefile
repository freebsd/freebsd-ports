# New ports collection makefile for:	byaccr
# Date created:		2 Nov 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	byaccr
PORTVERSION=	0.0
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://kt-www.jaist.ac.jp:8000/~ttate/ftp/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

EXAMPLES=	Parser.rb	Test.rb		cal.y

post-patch:
	${PERL} -i.orig -pe 's,^#include <malloc\.h>,#include <stdlib.h>,' ${WRKSRC}/*.[ch]

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/byaccr
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_EXAMPLESDIR}/byaccr/
.endfor
.endif

.include <bsd.port.mk>
