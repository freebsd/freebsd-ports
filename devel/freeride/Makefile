# New ports collection makefile for:	FreeRIDE
# Date created:		16 June 2004
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	freeride
PORTVERSION=	0.7.0
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/1208/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	Ruby Integrated Developement Environment written in Ruby

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/fox.so:${PORTSDIR}/x11-toolkits/ruby-fox \
		${RUBY_SITELIBDIR}/freebase/freebase.rb:${PORTSDIR}/devel/freebase

USE_RUBY=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

${WRKSRC}/install.rb: ${FILESDIR}/install.rb
	${CP} ${FILESDIR}/install.rb ${WRKSRC}/

pre-install: ${WRKSRC}/install.rb

install-noharm: pre-install
	cd ${WRKSRC}; ${RUBY} install.rb --no-harm

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/freeride ${PREFIX}/bin
	${CHMOD} a+w ${RUBY_SITELIBDIR}/freeride/config

.include <bsd.port.post.mk>
