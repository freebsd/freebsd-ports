# New ports collection makefile for:	FreeRIDE
# Date created:		16 June 2004
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	freeride
PORTVERSION=	0.6.0
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/256/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	Ruby Integrated Developement Environment written in Ruby

BROKEN=		Does not build

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/fox.so:${PORTSDIR}/x11-toolkits/ruby-fox \
		${RUBY_SITELIBDIR}/freebase/freebase.rb:${PORTSDIR}/devel/freebase

USE_RUBY=	yes
NO_BUILD=	yes

pre-install:
	${CP} ${FILESDIR}/install.rb ${WRKSRC}/

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/freeride ${PREFIX}/bin
	${CHMOD} a+w ${RUBY_SITELIBDIR}/freeride/config

.include <bsd.port.mk>
