# New ports collection makefile for:	RICA
# Date created:		10 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rica
PORTVERSION=	0.5
CATEGORIES=	irc ruby
MASTER_SITES=	http://www.koka-in.org/%7Ezophos/lib/rica/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_BZIP2=	yes
USE_RUBY=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MODULES=	rica.rb rica_utils.rb
DOCS=		classes_and_methods.txt	event.txt
EXAMPLES=	ricaco.rb	ricatest.rb

do-install:
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
