# New ports collection makefile for:	Ruby_libgtop
# Date created:		13 Apr 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libgtop
PORTVERSION=	0.1.0
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.colinsteele.org/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby_${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS=		ChangeLog README
EXAMPLES=	test.rb

post-install:
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
