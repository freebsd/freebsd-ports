# New ports collection makefile for:	ruby-exmars
# Date created:				22 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	exmars
PORTVERSION=	0.01
CATEGORIES=	games ruby
MASTER_SITES=	http://martinus.geekisp.com/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Ruby interface to the exMARS Memory Array Redcode Simulator

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

post-install:
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_MODEXAMPLESDIR}/Mars.rb

.include <bsd.port.mk>
