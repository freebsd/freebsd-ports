# New ports collection makefile for:	RubyGems
# Date created:		07 July 2004
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	gems
PORTVERSION=	0.8.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/1399/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	Package management framework for the Ruby language

USE_RUBY=	yes
RUBY_SETUP=	install.rb

NO_BUILD=	yes

BROKEN=		Incorrect pkg-plist

do-install:
	cd ${WRKSRC}; ${RUBY} ${RUBY_SETUP}

.include <bsd.port.mk>
