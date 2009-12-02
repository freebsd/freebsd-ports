# New ports collection makefile for:	Ruby/Taglib
# Date created:		18 Jan 2009
# Whom:			TOMIDA, Hiroaki <t.hiroaki.209 at gmail.com>
#
# $FreeBSD$
#

PORTNAME=	taglib
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	audio ruby
MASTER_SITES=	http://www.hakubi.us/ruby-taglib/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-taglib-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	t.hiroaki.209@gmail.com
COMMENT=	A Ruby library wrapping the Taglib library

LIB_DEPENDS=    tag:${PORTSDIR}/audio/taglib

USE_RUBY=	yes
USE_BZIP2=	yes

RUBY_RD_FILES=	taglib.rb

NO_BUILD=	yes

DOCS=		README

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/taglib.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
