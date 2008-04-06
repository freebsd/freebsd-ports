# New ports collection makefile for:	RubyGems
# Date created:		07 July 2004
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	gems
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	ruby${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	jw@innerewut.de
COMMENT=	Package management framework for the Ruby language

USE_RUBY=	yes
RUBY_SETUP=	setup.rb
RUBY_VER=	1.8

NO_BUILD=	yes

PLIST_SUB+=	DISTNAME="${DISTNAME}"

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
IGNORE=	already included in this ruby distribution
.endif

do-install:
	cd ${WRKSRC}; ${RUBY} ${RUBY_SETUP}

post-install:
	@${LN} -sf ${PREFIX}/bin/gem18 ${PREFIX}/bin/gem

.include <bsd.port.post.mk>
