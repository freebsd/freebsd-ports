# New ports collection makefile for:	Ruby-sysvipc
# Date created:		12 May 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sysvipc
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://deisui.bug.org/~ueno/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDTOOL=	yes

INSTALL_TARGET=	site-install

DOCS=		sysvipc.html	sysvipc.rd

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; ${RUBY_RD2} sysvipc.rd > sysvipc.html
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
