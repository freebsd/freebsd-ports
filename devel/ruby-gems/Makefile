# New ports collection makefile for:	RubyGems
# Date created:		07 July 2004
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	gems
PORTVERSION=	0.8.11
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/5207/
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

do-install:
	cd ${WRKSRC}; ${RUBY} ${RUBY_SETUP}

.include <bsd.port.mk>
